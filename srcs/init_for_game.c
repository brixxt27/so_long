/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_for_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:56:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/11 15:42:55 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	set_image(t_game_info *game_info)
{
	int	width;
	int	height;

	game_info->img.empty = mlx_xpm_file_to_image(game_info->mlx, \
												"assets/tile.xpm", \
												&width, &height);
	game_info->img.wall = mlx_xpm_file_to_image(game_info->mlx, \
												"assets/stone.xpm", \
												&width, &height);
	game_info->img.item = mlx_xpm_file_to_image(game_info->mlx, \
												"assets/ball.xpm", \
												&width, &height);
	game_info->img.exit = mlx_xpm_file_to_image(game_info->mlx, \
												"assets/ladder.xpm", \
												&width, &height);
	game_info->img.player = mlx_xpm_file_to_image(game_info->mlx, \
												"assets/player.xpm", \
												&width, &height);
}

void	init_mlx_window_image(t_game_info *game_info)
{
	game_info->mlx = mlx_init();
	game_info->window = mlx_new_window(game_info->mlx, IMG_SIZE, IMG_SIZE, \
										"jayoon_so_long");
	set_image(game_info);
}
