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

char	*ft_hola(char *buf)
{
	char	*line;
	static char	*rest;
	int	i;

	line = malloc(sizeof(char) * ft_strlen(buf));
	rest = malloc(sizeof(char) * ft_strlen(buf));
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			ft_strlcpy(rest, &buf[i], ft_strlen(buf));
			break ;
		}
		line[i] = buf[i];
		i++;
	}
	printf("%s\n", line);
	printf("%s\n", rest);
	free(line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buf;
	size_t	a;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	a = read(fd, buf, BUFFER_SIZE);
	while (a != 0)
	{
		ft_hola(buf);
		if (ft_strchr(buf, '\n'))	
			break ;
		a = read(fd, buf, BUFFER_SIZE);
		
	}
	return (buf);
}
