/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainpipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:53 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/10 19:14:15 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void	pip_menu(char **argv, char **envp)
// {
// 	int 	fd1[2];
// 	int 	fd2;
// 	int		pid;
// 	int		i;
// 	char	*pathname;

// 	pathname = (char *)malloc(6 + ft_strlen(argv[2]));
// 	if (!pathname)
// 		return ;
// 	ft_memmove(pathname, "/bin/", 6);
// 	pipe(fd1);
// 	pid = fork();
// 	fd2 = 0;
// 	if (pid == 0)
// 	{
// 		close(fd1[0]);
// 		dup2(fd1[1],STDOUT_FILENO);
// 		close(fd1[1]);
// 		ft_strlcat(pathname, argv[2], 7 + ft_strlen(argv[2]));
// 		execve(pathname,ft_split(argv[2], ' '),envp);
// 		exit(1);
// 	}
// 	else
// 	{
// 		close(fd1[1]);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			free(pathname);			
// 			if (access(argv[1],F_OK) == -1)
// 				fd2 = open(argv[4],O_CREAT);
// 			else if (access(argv[1],F_OK) != -1)
// 				fd2 = open(argv[4],O_WRONLY);
// 			dup2(fd1[0], STDIN_FILENO);
// 			close(fd1[0]);
// 			dup2(fd2, STDOUT_FILENO);
// 			pathname = (char *)malloc(6 + ft_strlen(argv[2]));
// 			if (!pathname)
// 				return ;
// 			ft_memmove(pathname, "/bin/", 6);
// 			ft_strlcat(pathname, argv[3], 7 + ft_strlen(argv[3]));
// 			execve(pathname,ft_split(argv[3],' '),envp);
// 			exit(1);
// 		}
// 		else
// 			close(fd1[0]);
// 	}
// 	wait(&i);
// 	wait(&i);
// }
#include "pipex.h"

void pip_menu(char **argv, char **envp)
{
	int fd1[2];
	int fd2;
	int pid;
	int i;
	char *pathname;

	// Crear el pipe
	pipe(fd1);
	
	// Crear el primer proceso
	pid = fork();
	if (pid == 0)
	{
		// Proceso hijo 1
		close(fd1[0]); // Cerrar el extremo de lectura
		dup2(fd1[1], STDOUT_FILENO); // Redirigir stdout al pipe
		close(fd1[1]); // Cerrar el extremo de escritura

		// Construir el pathname
		pathname = (char *)malloc(6 + ft_strlen(argv[2]));
		if (!pathname)
			return;
		ft_memmove(pathname, "/bin/", 6);
		ft_strlcat(pathname, argv[2], 7 + ft_strlen(argv[2]));

		// Ejecutar el comando
		char **args = ft_split(argv[2], ' ');
		execve(pathname, args, envp);
		perror("execve"); // Manejo de errores
		exit(1); // Salir si execve falla
	}
	else
	{
		// Crear el segundo proceso
		close(fd1[1]); // Cerrar el extremo de escritura
		pid = fork();
		if (pid == 0)
		{
			// Proceso hijo 2
			if (access(argv[1], F_OK) == -1)
				fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			else
				fd2 = open(argv[4], O_WRONLY | O_TRUNC);

			dup2(fd1[0], STDIN_FILENO); // Redirigir stdin al pipe
			close(fd1[0]); // Cerrar el extremo de lectura
			dup2(fd2, STDOUT_FILENO); // Redirigir stdout al archivo
			close(fd2); // Cerrar el archivo

			// Construir el pathname para el segundo comando
			pathname = (char *)malloc(6 + ft_strlen(argv[3]));
			if (!pathname)
				return;
			ft_memmove(pathname, "/bin/", 6);
			ft_strlcat(pathname, argv[3], 7 + ft_strlen(argv[3]));

			// Ejecutar el segundo comando
			char **args = ft_split(argv[3], ' ');
			execve(pathname, args, envp);
			perror("execve"); // Manejo de errores
			exit(1); // Salir si execve falla
		}
		else
		{
			// Proceso padre
			close(fd1[0]); // Cerrar el extremo de lectura
		}
	}

	// Esperar a que terminen los procesos hijos
	wait(&i);
	wait(&i);
}