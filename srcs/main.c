/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/01 16:47:32 by jayoon           ###   ########.fr       */
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

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_map_info	map_info;

	check_file_name(argc, argv[1]);
	map_info.map = parse(argv[1]);
	init_map_info(&map_info);
	check_map(&map_info);
	// mlx init
	// window
	// hook key mapping
	// loop
	// free all
	free_map(&map_info);
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
