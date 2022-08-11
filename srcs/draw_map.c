/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:42:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/11 16:57:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	init_position(char ***map, size_t *x, size_t *y, t_game_info \
							*game_info)
{
	*map = game_info->map_info.map;
	*x = 0;
	*y = 0;
}

static void	draw_image(t_game_info *game_info, void *image, \
						size_t s_x, size_t s_y)
{
	int	x;
	int	y;

	x = (int)s_x;
	y = (int)s_y;
	mlx_put_image_to_window(game_info->mlx, game_info->window, image, \
							x * IMG_SIZE, y * IMG_SIZE);
}
void	draw_map(t_game_info *game_info)
{
	char	**map;
	size_t	x;
	size_t	y;

	init_position(&map, &x, &y, game_info);
	while (y < game_info->map_info.col)
	{
		x = 0;
		while (x < game_info->map_info.row)
		{
			if (map[y][x] == '0')
				draw_image(game_info, game_info->img.empty, x, y);
			else if (map[y][x] == '1')
				draw_image(game_info, game_info->img.wall, x, y);
			else if (map[y][x] == 'C')
				draw_image(game_info, game_info->img.item, x, y);
			else if (map[y][x] == 'E')
				draw_image(game_info, game_info->img.exit, x, y);
			else
				draw_image(game_info, game_info->img.player, x, y);
		}
	}
}
