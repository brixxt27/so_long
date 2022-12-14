/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:06:05 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/12 20:17:50 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

# include <stdlib.h>
# include "so_long.h"

typedef struct s_cnt
{
	size_t	p;
	size_t	e;
}	t_cnt;

typedef struct s_idx_of_rectangular
{
	size_t	col;
	size_t	row;
}	t_idx;

void	check_file_name(int argc, char *file);
void	check_map(t_game_info *game_info);
void	check_inner_and_count_characters(t_game_info *game_info);

#endif
