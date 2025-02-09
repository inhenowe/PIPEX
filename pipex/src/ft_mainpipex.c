/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainpipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:53 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/09 16:23:55 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_menu(char **argv)
{
	int		fd;
	char	*path_command;

	path_command = malloc(sizeof(char) * 20);
	fd = open(argv[1],O_RDWR);
	ft_memmove(path_command, "/bin/", 6);
	ft_strjoin(path_command, argv[2]);
	ft_printf("%s",path_command);
}
