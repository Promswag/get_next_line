/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:32:05 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/09 14:25:13 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	gnl_is_a_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static char	*gnl_buffer_handler(int fd, char *str)
{
	char	*tmp;
	int		reading;

	reading = 1;
	while (gnl_is_a_line(str) == -1 && reading)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp)
		{
			reading = read(fd, tmp, BUFFER_SIZE + 1);
			tmp[reading] = '\0';
			str = ft_strjoin(str, tmp);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*next_line;
	int			index;

	if (!tmp)
	{
		tmp = malloc(sizeof(char));
		*tmp = '\0';
	}
	tmp = gnl_buffer_handler(fd, tmp);
	index = gnl_is_a_line(tmp) + 1;
	if (!index)
	{
		line = tmp;
		tmp = NULL;
		return (line);
	}
	line = ft_substr(tmp, 0, index);
	next_line = ft_substr(tmp, index, ft_strlen(tmp) - index);
	free(tmp);
	tmp = next_line;
	return (line);
}
