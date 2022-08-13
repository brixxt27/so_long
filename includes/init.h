/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:45:44 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/13 20:47:42 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "so_long.h"

void	init_map_info_and_steps(t_map_info *map_info, t_position *pos);
void	init_mlx_window_image(t_game_info *game_info);

#endif
