/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:17:27 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/11 17:18:58 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		ctu_s1s2;
	size_t		ctu_s3;
	char		*new_str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	ctu_s1s2 = 0;
	ctu_s3 = 0;
	while (s1[ctu_s1s2])
		new_str[ctu_s3++] = s1[ctu_s1s2++];
	ctu_s1s2 = 0;
	while (s2[ctu_s1s2])
		new_str[ctu_s3++] = s2[ctu_s1s2++];
	new_str[ctu_s3] = '\0';
	free(s1);
	return (new_str);
}
