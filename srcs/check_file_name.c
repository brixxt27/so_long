/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:50:51 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/10 17:45:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

void	check_file_name(int argc, char *file)
{
	char	*str;

	if (argc != 2)
		print_error("one argument");
	str = ft_strrchr(file, '.');
	check_error(LIBFT, "ft_strrchr", (ssize_t)str);
	if (ft_strncmp(str, ".ber", 5))
		print_error(".ber extension");
}
