/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:16:46 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/02/21 15:08:19 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)&s[i + 1]);
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
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	a;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	a = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	dst = malloc(sizeof(char) * a);
	if (!dst)
		return (NULL);
	dst = ft_strlcat(dst, s1, s2);
	free(s1);
	return (dst);
}

char	*ft_strlcat(char *dst, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
