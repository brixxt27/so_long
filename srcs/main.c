/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/11 16:39:49 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "init.h"
#include "parse.h"
#include "so_long.h"
#include "libft.h"

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
	init_map_info(&game_info.map_info);
	check_map(&game_info.map_info);
	init_mlx_window_image(&game_info);
	draw_map(&game_info);
	// mlx_hook(game_info.mlx_info.p_win, ON_KEYDOWN, 0, \
	// 	&on_keydown_callback, &game_info);
	// mlx_hook(game_info.mlx_info.p_win, ON_DESTROY, 0, \
	// 	&on_destroy_callback, &game_info);
	// mlx_loop(game_info.mlx_info.p_mlx);
	free_map(&game_info.map_info);
	return (0);
}

	// int i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	ft_safe_free(map[i]);
	// 	i++;
	// }
	// free(map);
	// map = NULL;
	// system("leaks so_long");
