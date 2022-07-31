/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/31 18:35:15 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "parse.h"

int	main(int argc, char *argv[])
{
	check_argv(argc, argv);
	parse(argc, argv);
	// check map
	// mlx init
	// window
	// hook key mapping
	// loop
	return (0);
}
