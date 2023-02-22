/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:49:41 by david             #+#    #+#             */
/*   Updated: 2023/02/22 07:49:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;

	char	*line;
	char	*line1;
	char	*line2;

	fd = open("text",  O_RDONLY);
	fd1 = open("text1",  O_RDONLY);
	fd2 = open("text2",  O_RDONLY);
	if (fd <= 0 || fd1 <= 0 || fd2 <= 0)
		return (0);

	while (1)
	{
		line = get_next_line(fd);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line == NULL || line1 == NULL || line2 == NULL)
			break ;
		printf("%s", line);
		printf("%s", line1);
		printf("%s", line2);
		free (line);
		free (line1);
		free (line2);
	}
	return (0);
}
