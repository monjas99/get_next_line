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

char	*ft_text(char *buf)
{
	char	*line;
	char	*rest = malloc(sizeof(char) * 100);
	int	i;

	//rest = malloc(sizeof(char) * ft_strlen(buf));
	line = malloc(sizeof(char) * ft_strlen(buf) + 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i])
		rest = ft_strjoin(rest, &buf[i]);
	printf("%s", line);
	printf("%s", rest);
	free(line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int	a;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	a = (int)read(fd, buf, BUFFER_SIZE);
	while (a != 0)
	{
		ft_text(buf);
		//if (ft_strchr(buf, '\n'))	
		//	break ;
		a = read(fd, buf, BUFFER_SIZE);		
	}
	write (1, "\n", 1);
	return (buf);
}
