# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/08/11 21:08:12 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=address

LIBFT_FLAGS =	-L$(LIBFT_DIR) -lft
MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCS_FLAGS	=	-I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INCS_DIR)

MLX_AR		=	libmlx.a
LIBFT_AR	=	libft.a

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR 	=	./includes/
MLX_DIR		=	./mlx/
LIBFT_DIR	=	./libft/

SRCS_NAME	=	check_file_name.c \
				check_inner_and_count_characters.c \
				check_map.c \
				draw_map.c \
				error.c \
				init_map_row_and_col.c \
				init_mlx_window_image.c \
				main.c \
				parse.c
OBJS_NAME	=	$(SRCS_NAME:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))
LIBFT		=	$(LIBFT_DIR)$(LIBFT_AR)
MLX			=	$(MLX_DIR)$(MLX_AR)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS_FLAGS) -c $< -o $@

# $(OBJS): $(SRCS) $(OBJS_DIR)
# 	$(CC) $(CFLAGS) $(INCS_FLAGS) -c $(SRCS) -o $@

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean
	make all

# bonus: $(BONUS_NAME)
# .PHONY: bonus

.PHONY: all clean fclean re debug
