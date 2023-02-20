/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/20 12:42:34 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*ft_next_line(char *saved)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	next_line = (char *)malloc((ft_strlen(saved) - i + 1) * sizeof(char));
	if (!next_line)
	{
		return (NULL);
	}
	i++;
	j = 0;
	while (saved[i])
		next_line[j++] = saved[i++];
	next_line[j] = '\0';
	free(saved);
	saved = NULL;
	return (next_line);
}

static char	*ft_find_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read_and_save(int fd, char *saved)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(saved, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(saved);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_read_and_save(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_find_line(saved);
	saved = ft_next_line(saved);
	return (line);
}
