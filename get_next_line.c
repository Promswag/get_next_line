/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:32:05 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/08 18:00:25 by gbaumgar         ###   ########.fr       */
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
	while (!gnl_is_a_line(str) && reading)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp)
		{
			reading = read(fd, tmp, BUFFER_SIZE + 1);
			str = ft_strjoin(str, tmp);
		}
		else
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*next_line;
	int			index;

	if (tmp == NULL)
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read(fd, tmp, BUFFER_SIZE + 1);
	}	
	if (tmp)
		gnl_buffer_handler(fd, tmp);
	printf("%s", tmp);
	printf("1\n");
	index = gnl_is_a_line(tmp) + 1;
	printf("2\n");
	line = ft_substr(tmp, 0, index);
	printf("3\n");
	next_line = ft_substr(tmp, index, ft_strlen(tmp) - index);
	printf("4\n");
	free(tmp);
	printf("5\n");
	tmp = next_line;
	printf("6\n");
	return (line);
}
