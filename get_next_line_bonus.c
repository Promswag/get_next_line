/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:39:27 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/09 17:18:51 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char	buffer[BUFFER_SIZE + 1];
	int		reading;

	reading = 1;
	if (!str)
		return (NULL);
	while (gnl_is_a_line(str) == -1 && reading)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading < 0)
		{
			free(str);
			return (NULL);
		}
		buffer[reading] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*gnl_retrieve_line(char **str)
{
	char	*line;
	char	*next_line;
	int		index;

	index = gnl_is_a_line(*str);
	if (index == -1)
	{
		line = *str;
		*str = NULL;
		return (line);
	}
	line = ft_substr(*str, 0, index + 1);
	next_line = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = next_line;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];

	if (fd < 0)
		return (NULL);
	if (!tmp[fd])
	{
		tmp[fd] = malloc(sizeof(char));
		*tmp[fd] = '\0';
	}
	tmp[fd] = gnl_buffer_handler(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	if (!ft_strlen(tmp[fd]))
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	return (gnl_retrieve_line(&tmp[fd]));
}
