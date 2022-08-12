/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/12 21:57:27 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define IMG_SIZE 64
# define KEY_ESC 53

enum e_key_of_event
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

enum e_key_of_direction
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13
};

typedef struct s_map_info
{
	char	**map;
	size_t	row;
	size_t	col;
	size_t	cnt_c;
	size_t	steps;
}	t_map_info;

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*item;
	void	*exit;
	void	*player;
}	t_img;

typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_position;

typedef struct s_game_info
{
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_img		img;
	t_position	pos;
}	t_game_info;

void	draw_map(t_game_info *game_info);
int		do_it_at_key_down(int key_down, void *param);
int		do_it_at_click_x(void *param);
void	move_player(t_game_info *param, t_position *curr, t_position *next);

#endif
