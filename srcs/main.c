/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/14 16:11:15 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "init.h"
#include "libft.h"
#include "mlx.h"
#include "parse.h"
#include "so_long.h"

static void	free_map(t_map_info *p_map_info)
{
	size_t	i;

	i = 0;
	while (p_map_info->map[i])
	{
		ft_safe_free(p_map_info->map[i]);
		i++;
	}
	ft_safe_free(p_map_info->map);
}

int	main(int argc, char *argv[])
{
	t_game_info	game_info;

	check_file_name(argc, argv[1]);
	game_info.map_info.map = parse(argv[1]);
	init_map_info_and_steps(&game_info.map_info, &game_info.pos);
	check_map(&game_info);
	init_mlx_window_image(&game_info);
	draw_map(&game_info);
	mlx_hook(game_info.window, ON_KEYDOWN, 0, \
		do_it_at_key_down, &game_info);
	mlx_hook(game_info.window, ON_DESTROY, 0, \
		do_it_at_click_x, &game_info);
	mlx_loop(game_info.mlx);
	free_map(&game_info.map_info);
	return (0);
}
