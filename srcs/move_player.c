/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:22:06 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/12 22:00:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move_player(t_game_info *param, t_position *curr, t_position *next)
{
	printf("Number of steps : %zu\n", ++param->map_info.steps);
	change_map()
	// if 0 || C
		// 현재를 0, 다음을 P
		// curr 에 next 대입하기
	// else if E && cnt_c == 0
		// printf 클리어 축하 메시지
		// 종료
	// 변경된 map 으로 이미지 렌더링
}
