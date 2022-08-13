/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info_and_steps.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:42:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/13 20:48:58 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	init_row(t_map_info *p_map_info)
{
	size_t	i;

	i = 0;
	while (p_map_info->map[i])
		i++;
	p_map_info->row = i;
}

static void	init_col(t_map_info *p_map_info)
{
	p_map_info->col = ft_strlen(p_map_info->map[0]);
}

static void	init_cnt_c(t_map_info *p_map_info)
{
	p_map_info->cnt_c = 0;
}

static void	init_steps(t_position *pos)
{
	pos->steps = 0;
}

void	init_map_info_and_steps(t_map_info *p_map_info, t_position *pos)
{
	init_row(p_map_info);
	init_col(p_map_info);
	init_cnt_c(p_map_info);
	init_steps(pos);
}
