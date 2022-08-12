/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:56:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/12 21:43:02 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "mlx.h"

static void	set_image(t_game_info *game_info)
{
	int	width;
	int	height;

	game_info->img.empty = mlx_xpm_file_to_image(game_info->mlx, \
		"./assets/empty.xpm", &width, &height);
	game_info->img.wall = mlx_xpm_file_to_image(game_info->mlx, \
		"./assets/wall.xpm", &width, &height);
	game_info->img.item = mlx_xpm_file_to_image(game_info->mlx, \
		"./assets/item.xpm", &width, &height);
	game_info->img.exit = mlx_xpm_file_to_image(game_info->mlx, \
		"./assets/exit.xpm", &width, &height);
	game_info->img.player = mlx_xpm_file_to_image(game_info->mlx, \
		"./assets/player.xpm", &width, &height);
}

void	init_mlx_window_image(t_game_info *game_info)
{
	printf("Game start!\n");
	game_info->mlx = mlx_init();
	game_info->window = mlx_new_window(game_info->mlx, \
		game_info->map_info.col * IMG_SIZE, \
		game_info->map_info.row * IMG_SIZE, "jayoon's adventure");
	set_image(game_info);
}
