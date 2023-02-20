/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:03:22 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/20 11:35:06 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{	
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("text", O_RDONLY);
	if (fd <= 0)
		return (0);
	while (i < 9)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free (line);
	}
	return (0);
}
