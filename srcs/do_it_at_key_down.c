/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_at_key_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:33:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/14 16:21:18 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

static void	what_is_next(int key_down, t_position *curr, t_position *next)
{
	if (key_down == KEY_A)
	{
		next->x = curr->x - 1;
		next->y = curr->y;
	}
	else if (key_down == KEY_S)
	{
		next->x = curr->x;
		next->y = curr->y + 1;
	}
	else if (key_down == KEY_D)
	{
		next->x = curr->x + 1;
		next->y = curr->y;
	}
	else
	{
		next->x = curr->x;
		next->y = curr-> y - 1;
	}
}

static int	is_movable(int key_down, t_game_info *info, t_position *next)
{
	char		**map;

	map = info->map_info.map;
	what_is_next(key_down, &info->pos, next);
	if (map[next->y][next->x] == '0' || map[next->y][next->x] == 'C' || \
		(map[next->y][next->x] == 'E' && info->map_info.cnt_c == 0))
		return (1);
	return (0);
}

void	exit_game(t_game_info *game_info)
{
	mlx_destroy_window(game_info->mlx, game_info->window);
	exit(0);
}

int	do_it_at_click_x(void *param)
{
	printf("Game over!\n");
	exit_game((t_game_info *)param);
	return (0);
}

int	do_it_at_key_down(int key_down, t_game_info *param)
{
	t_position	next;

	next.steps = param->pos.steps;
	if (key_down == KEY_A || key_down == KEY_S \
		|| key_down == KEY_D || key_down == KEY_W)
	{
		if (is_movable(key_down, (t_game_info *)param, &next))
			move_player((t_game_info *)param, &((t_game_info *)param)->pos, \
				&next);
	}
	else if (key_down == KEY_ESC)
	{
		printf("Game over!\n");
		exit_game((t_game_info *)param);
	}
	return (0);
}
