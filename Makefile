# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/07/31 21:28:34 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -g3 -fsanitize=address

# mlx
MLXFLAGS	= -L./mlx -lmlx -framework OpenGL -framework AppKit
MLX_DIR		= mlx
MLX_ARCHIVE	= libmlx.a

SRCS_DIR	= srcs
# B_SRCS_DIR	= bonus_srcs
INCS_DIR 	= includes

LIBFT_DIR	= libft
LIBFT		= libft.a

SRCS		= 	$(addprefix $(SRCS_DIR)/,\
				main.c \
				check_file_name.c \
				error.c \
				parse.c \
				check_map)

# B_SRCS		=	$(addprefix $(B_SRCS_DIR)/,\
# 				main_bonus.c)

OBJS		= $(SRCS:.c=.o)
# B_OBJS		= $(B_SRCS:.c=.o)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $^ -o $@

# mlx. Focus on NAME target!
$(NAME): $(OBJS) $(MLX_DIR)/$(MLX_ARCHIVE)
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) ./
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# mlx
$(MLX_DIR)/$(MLX_ARCHIVE):
	make -C $(MLX_DIR)

# $(BONUS_NAME): $(B_OBJS)
# 	@make bonus -C $(LIBFT_DIR)
# 	@cp $(LIBFT_DIR)/$(LIBFT) ./
# 	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(B_OBJS) $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re:
	@make re -C $(LIBFT_DIR)
	make clean
	make all

# bonus: $(BONUS_NAME)
# .PHONY: bonus

.PHONY: all clean fclean re debug
