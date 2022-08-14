/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:22:06 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/14 16:18:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

static void	update_steps(t_position *curr, t_position *next)
{
	curr->steps = next->steps;
	curr->x = next->x;
	curr->y = next->y;
}

static void	do_it_on_item(t_map_info *map_info, t_position *curr, \
	t_position *next, t_game_info *param)
{
	map_info->cnt_c--;
	printf("Left items: %zu\n", map_info->cnt_c);
	map_info->map[curr->y][curr->x] = '0';
	map_info->map[next->y][next->x] = 'P';
	mlx_put_image_to_window(param->mlx, param->window, param->img.empty, \
		next->x * IMG_SIZE, next->y * IMG_SIZE);
	if (map_info->cnt_c == 0)
		printf("Go exit!\n");
}

static void	print_changed_map(t_map_info *map_info, t_position *curr, \
	t_position *next, t_game_info *param)
{
	if (map_info->map[next->y][next->x] == '0')
	{
		map_info->map[curr->y][curr->x] = '0';
		map_info->map[next->y][next->x] = 'P';
	}
	else if (map_info->map[next->y][next->x] == 'C')
	{
		do_it_on_item(map_info, curr, next, param);
	}
	else if (map_info->map[next->y][next->x] == 'E' && map_info->cnt_c == 0)
	{
		printf("Congratulation! Game clear!");
		exit_game(param);
	}
	mlx_put_image_to_window(param->mlx, param->window, param->img.empty, \
		curr->x * IMG_SIZE, curr->y * IMG_SIZE);
	mlx_put_image_to_window(param->mlx, param->window, param->img.player, \
		next->x * IMG_SIZE, next->y * IMG_SIZE);
}

void	move_player(t_game_info *param, t_position *curr, t_position *next)
{
	printf("Number of steps : %zu\n", ++next->steps);
	print_changed_map(&param->map_info, curr, next, param);
	update_steps(curr, next);
}
