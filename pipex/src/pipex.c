/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:47 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/09 13:48:47 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		perror("Faltan argumentos");
	if(access(argv[1],F_OK) == -1)
		perror("El archivo o directorio no existe.");
	pip_menu(argv);
}
