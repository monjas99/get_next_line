/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/21 15:20:22 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save(char *stash)
{
	char	*save;
	int		x;

	x = (ft_strlen(ft_strchr(stash)) + 1);
	if (ft_strchr(stash) == 0)
	{
		free(stash);
		return (NULL);
	}
	save = malloc(sizeof(char) * x);
	if (!save)
		return (NULL);
	ft_strlcpy(save, ft_strchr(stash), x);
	free(stash);
	return (save);
}
static char	*ft_line(char *stash)
{
	char	*line;
	int		i;
	
	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash [i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = stash[i];
	return (line);
}

static char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		a;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)	
		return (NULL);
	a = 1;
	while (!ft_strchr(stash) && a != 0)
	{
		a = (int)read(fd, buf, BUFFER_SIZE);
		if (a == -1)
		{
		 	free(buf);
			free(stash);
			return (NULL);
		}
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_save(stash); 
	return (line);
}
