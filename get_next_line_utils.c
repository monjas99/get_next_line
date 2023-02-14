/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:46 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/14 12:03:00 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(char *s)
{
    int i;
    int j;

    j = ft_strlen(s);
    i = 0;
    while (i <= j)
    {
        if (s[i] == '\n')
        {
            return ((char *)&s[i + 1]);
        }
        i++;
    }
    return (0);
}

size_t	ft_strlcpy(
	char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *dst;
        size_t  a;

        a = (ft_strlen(s1) + ft_strlen(s2)) + 1;
        dst = malloc(sizeof(char) * a);
        if (dst == 0)
                return (0);
        ft_strlcpy(dst, s1, (ft_strlen(s1) + 1));
        ft_strlcat(dst, s2, a);
//		free (s1);
//		free (s2);
        return (dst);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  j;
        size_t  k;

        k = ft_strlen(src);
        i = 0;
        while (dst[i] && i < dstsize)
                i++;
        j = 0;
        while (src[j] && (i + j + 1) < dstsize)
        {
                dst[i + j] = src[j];
                j++;
        }
        if (i < dstsize)
                dst[i + j] = '\0';
        return (i + k);
}
