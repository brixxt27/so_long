/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inner_and_count_characters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:44:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/12 20:22:42 by jayoon           ###   ########.fr       */
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

static void	count_characters(char **map, t_idx *idx, t_cnt *cnt, \
							t_game_info *game_info)
{
	if (map[idx->row][idx->col] == 'P')
	{
		game_info->pos.x = idx->col;
		game_info->pos.y = idx->row;
		cnt->p++;
	}
	else if (map[idx->row][idx->col] == 'E')
		cnt->e++;
	else if (map[idx->row][idx->col] == 'C')
		game_info->map_info.cnt_c++;
	else if (map[idx->row][idx->col] == '0' || \
			map[idx->row][idx->col] == '1')
		;
	else
		print_error("It is not correct characters");
}

void	check_inner_and_count_characters(t_game_info *game_info)
{
	t_cnt	cnt;
	t_idx	idx;
	char	**map;

	map = init_utils(&cnt, &idx, &game_info->map_info);
	while (idx.row < game_info->map_info.row - 1)
	{
		idx.col = 1;
		while (idx.col < game_info->map_info.col - 1)
		{
			count_characters(map, &idx, &cnt, game_info);
			idx.col++;
		}
		idx.row++;
	}
	check_minimum_conditions(&cnt, &game_info->map_info);
}
