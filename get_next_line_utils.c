/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:32:43 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/08 17:59:39 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		j = 0;
		while (*(s1 + j))
			*(str + i++) = *(s1 + j++);
		j = 0;
		while (*(s2 + j))
			*(str + i++) = *(s2 + j++);
		str[i] = '\0';
	}
	free(s1);
	free(s2);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (start > l)
	{
		str = malloc(1);
		if (str)
		{
			str[0] = '\0';
			return (str);
		}
		return (NULL);
	}
	if (start + len > l)
		len = l - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str)
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	if (dstsize)
	{
		while (i < l && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}
