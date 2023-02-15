/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:17 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/15 11:52:54 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_aux(char *buf, char *stash)
{
	char	*line;
	char	*aux; 
	int		i;

	i = 0;
	line = malloc(sizeof(char) * BUFFER_SIZE);
	aux = ft_strchr(buf);
	stash = malloc(sizeof(char) * ft_strlen(aux) + 1);
	ft_strlcpy(stash, aux, ft_strlen(aux) + 1);
	while (buf[i] != '\n')
	{
		line [i] = buf[i];
		i++;
	}
	return (line);
}

char    *get_next_line(int fd)
{
	int         a;
	char        *line;
	char        *buf;
	static char *stash = "0";

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	a = (int)read(fd, buf, BUFFER_SIZE);
	line = malloc(sizeof(char) * 1);
	if  (buf == NULL)
		return (NULL);
	while (a != 0)
	{
		if (ft_strchr(buf) == 0)
			line = ft_strjoin(line, buf);	
		else if (ft_strchr(buf) != 0)
		{
			line = ft_strjoin(line, ft_aux(buf, stash));
			break ;
		}
		a = (int)read(fd, buf, BUFFER_SIZE);
	}
	printf("%s\n", line);
	return (line);
 }
