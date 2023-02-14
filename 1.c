/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/14 11:04:42 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_space(char *hard)
{
	int	i;

	i = 0;
	while (hard[i])
	{
		if (hard[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_text(char *buf, char *hard)
{
	char	*line;
	int		i;
	
	hard = ft_strjoin(hard, buf);
	i = ft_space(hard);
	line = NULL;
	if (ft_strchr(hard) != 0)
	{
		line = malloc(sizeof(char) * i + 1);
		ft_strlcpy(line, hard, i + 1);
	}
	else if (ft_strchr(hard) == 0)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	char 		*line;
	int			a;
	char		*buf;
	static char	*hard;
	
	hard = malloc(sizeof(char) * 1);
	if (hard == NULL)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	a = (int)read(fd, buf, BUFFER_SIZE);
	line = ft_text(buf, hard);

	return (line);
}
