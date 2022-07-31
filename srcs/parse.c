/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:34:55 by jayoon            #+#    #+#             */
/*   Updated: 2022/07/31 19:14:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "fcntl.h"
#include "error.h"

void	parse(int argc, char *argv[])
{
	int		fd;
	char	*path;
	char	*ret_gnl;
	char	*join;
	char	*temp;

	path = ft_strjoin("../map/", argv[1]);
	check_error(LIBFT, "ft_strjoin", (ssize_t)path);
	fd = open(path, O_RDONLY);
	check_error(SYSTEM_CALL, "open", (ssize_t)fd);
	join = "";
	ret_gnl = get_next_line(fd);
	check_error(LIBFT, "get_next_line", (ssize_t)ret_gnl);
	join = ft_strjoin(join, ret_gnl);
	while (ret_gnl)
	{
		free(ret_gnl);
		ret_gnl = get_next_line(fd);
		check_error(LIBFT, "get_next_line", (ssize_t)ret_gnl);
		temp = join;
		join = ft_strjoin(join, ret_gnl);
		free(temp);
	}
}
