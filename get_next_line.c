/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/14 11:55:34 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int	ft_space(char *hard)
{
	int	i;

	i = 0;
	while (hard[i])
	{
		if (hard[i] == '\n')
			return (i);
		i++;
	}char *s1, char *s2
	return (0);
}*/

/*char	*ft_text(char *buf, char *hard)
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
}*/

char	*ft_void(char *hard, char *buf)
{
	char	*aux;
	int		i = 0;
	char	*x;

	hard = malloc(sizeof(char) * 1);
	x = ft_strchr(buf);
	if (ft_strchr(buf) != 0)
		hard = ft_strjoin(hard, x);
	printf("%s", hard);	
	return (aux);
}

char	*get_next_line(int fd)
{
	char 		*line;
	int			a;
	char		*buf;
	static char	*hard = "0";

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	a = (int)read(fd, buf, BUFFER_SIZE);
	if	(buf == NULL)
		return (NULL);
	if (hard == "0")
		line = ft_void(hard, buf);
	/*
	else if (hard != "0")
	{

	}*/

	return (line);
}
