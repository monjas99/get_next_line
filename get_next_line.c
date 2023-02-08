/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/07 20:07:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*ft_hola(char *buf)
{
	char *line;

	line = malloc(sizeof(char) * ft_strlen(buf));
	ft_strlcpy(line, buf , ft_strlen(buf));
	printf("%s", line);
	free(line);
	return (buf);
} */

char	*get_next_line(int fd)
{
	//char	*line;
	char	*buf;
	size_t	a;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	a = read(fd, buf, BUFFER_SIZE);
	while (a != 0)
	{
		printf("%s", buf);
		//ft_hola(buf);
		if (ft_strchr(buf, '\n'))	
			break ;
		a = read(fd, buf, BUFFER_SIZE);
		
	}
	return (buf);
}
