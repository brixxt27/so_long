/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/10 13:40:24 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

typedef struct s_map_info
{
	char	**map;
	size_t	row;
	size_t	col;
	size_t	cnt_c;
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

typedef struct s_tool_for_game
{
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_img		img;
	t_position	pos;
}	t_tool;

#endif
