/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainpipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:53 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/11 19:15:04 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
                                                                               
#include "pipex.h"

void	pip_menu(char **argv,char **envp)
{
	int 	fd1[2];
	int 	procesor_id;
	char	*sourcepath;
	char	**candf;

	sourcepath = (char *)malloc(6 + ft_strlen(argv[2]));
	if (!sourcepath)
		return;
	ft_memmove(sourcepath, "/bin/", 6);
	candf = ft_split(argv[2], ' ');
	if (pipe(fd1) == -1)
	{
		perror("pipe");
		exit(1);
	}
	procesor_id = fork();
	if (procesor_id == 0)
		offspring_read(argv, envp, ft_strjoin(sourcepath,candf[0]), fd1);
	else
	{
		close(fd1[WRITE_SIDE]); 
		procesor_id = fork();
		candf = ft_split(argv[3], ' ');
		if (procesor_id == 0)
			offspring_write(argv, envp, ft_strjoin(sourcepath,candf[0]), fd1);
		else
			close(fd1[READ_SIDE]);
	}
	free(sourcepath);
	free(candf);
}
