/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:22:06 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/13 22:00:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

static void	update_steps(t_position *curr, t_position *next)
{
	curr->steps = next->steps;
	curr->x = next->x;
	curr->x = next->y;
}


#include <stdio.h>
static void	print_changed_map(t_map_info *map_info, t_position *curr, \
	t_position *next, t_game_info *param)
{
	// test
	int y = 0;
	while (map_info->map[y])
	{
		printf("%s\n", map_info->map[y]);
		y++;
	}


	if (map_info->map[next->y][next->x] == '0')
	{
		map_info->map[curr->y][curr->x] = '0';
		map_info->map[next->y][next->x] = 'P';
	}
	else if (map_info->map[next->y][next->x] == 'C')
	{
		map_info->cnt_c--;
		map_info->map[curr->y][curr->x] = '0';
		map_info->map[next->y][next->x] = 'P';
	}
	else if (map_info->map[next->y][next->x] == 'E' && map_info->cnt_c == 0)
	{
		exit_game(param);
		printf("Congratulation! Game clear!");
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
