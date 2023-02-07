/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:03:22 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:13 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{	
	int		fd;
	char	*line;
	fd = open("text", O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
//	printf("%s\n", line);
    return(0);
}

