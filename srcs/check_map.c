/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:27:40 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/31 22:04:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_edge(char **map)
{
	check_top_and_bottom(map[0], map[]);
	check_left_and_right();
}

static void	check_inner(char **map)
{

}

void	check_map(t_map_info *p_map_info)
{
	check_edge(p_map_info);
	check_inner(p_map_info);
}
