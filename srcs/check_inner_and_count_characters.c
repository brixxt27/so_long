/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inner_and_count_characters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:44:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/01 14:17:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "exception.h"
#include "so_long.h"

static char	**init_utils(t_cnt *p_cnt, t_idx *p_idx, t_map_info *p_map_info)
{
	p_cnt->e = 0;
	p_cnt->p = 0;
	p_idx->col = 1;
	p_idx->row = 1;
	return (p_map_info->map);
}

static void	check_minimum_conditions(t_cnt *p_cnt, t_map_info *p_map_info)
{
	if (p_cnt->p != 1)
		print_error("Map must have one player");
	if (p_cnt->e == 0)
		print_error("Map must have at least one exit");
	if (p_map_info->cnt_c == 0)
		print_error("Map must have at least one collectible");
}

void	check_inner_and_count_characters(t_map_info *p_map_info)
{
	t_cnt	cnt;
	t_idx	idx;
	char	**map;

	map = init_utils(&cnt, &idx, p_map_info);
	while (idx.row < p_map_info->row - 1)
	{
		while (idx.col < p_map_info->col - 1)
		{
			if (map[idx.row][idx.col] == 'P')
				cnt.p++;
			else if (map[idx.row][idx.col] == 'E')
				cnt.e++;
			else if (map[idx.row][idx.col] == 'C')
				p_map_info->cnt_c++;
			else if (map[idx.row][idx.col] == '0' || \
						map[idx.row][idx.col] ==  '1')
				continue ;
			else
				print_error("It is not correct characters");
			idx.col++;
		}
		idx.row++;
	}
	check_minimum_conditions(&cnt, p_map_info);
}
