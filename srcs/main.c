/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/01 13:35:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "init.h"
#include "parse.h"
#include "so_long.h"

#include "libft.h"
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
