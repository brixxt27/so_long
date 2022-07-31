/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:50:51 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/31 18:31:32 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

void	check_argv(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
		print_error();
	str = ft_strrchr(argv[1], '.');
	check_error(LIBFT, "ft_strrchr", (ssize_t)str);
	if (ft_strncmp(str, ".ber", 4))
		print_error();
}
