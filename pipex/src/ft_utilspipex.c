/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilspipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:50 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/11 17:20:49 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	offspring_read(char **data, char **envp, char *path, int fd1[2])
{
	char	**args;
	int		fd2;

	fd2 = 0;
	close(fd1[READ_SIDE]);
	if (access(data[1], F_OK) == -1)
		ft_printf("archivo %s inexistente", data[1]);
	else
		fd2 = open(data[1], O_RDONLY);
	dup2(fd2,STDIN_FILENO);
	close(fd2);
	dup2(fd1[WRITE_SIDE], STDOUT_FILENO);
	close(fd1[WRITE_SIDE]);
	args = ft_split(data[2], ' ');
	execve(path, args, envp);
	perror("exceve1");
	exit(1);

}

void	offspring_write(char **data, char **envp, char *path, int fd1[2])
{
	char	**args;
	int		fd2;

	fd2 = 0;
	if (access(data[4], F_OK) == -1)
		fd2 = open(data[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		fd2 = open(data[4], O_WRONLY | O_TRUNC);
	dup2(fd1[READ_SIDE], STDIN_FILENO);
	close(fd1[READ_SIDE]);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	args = ft_split(data[3], ' ');
	execve(path, args, envp);
	perror("execve2");
	exit(1);
}
