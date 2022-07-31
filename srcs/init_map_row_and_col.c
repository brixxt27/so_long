/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_row_and_col.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:42:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/31 22:05:27 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	cal_row(t_map_info *p_map_info)
{
	size_t	i;

	i = 0;
	while (p_map_info->map[i])
		i++;
	p_map_info->row = i;
}

static void	cal_col(t_map_info *p_map_info)
{
	p_map_info->col = ft_strlen(p_map_info->map[0]);
}

void	init_map_row_and_col(t_map_info *p_map_info)
{
	cal_row(p_map_info);
	cal_col(p_map_info);
}
