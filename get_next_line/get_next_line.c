/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:35 by jalsadik          #+#    #+#             */
/*   Updated: 2026/03/11 15:44:55 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static char	*read_and_store(int fd, char *leftover)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	bytes = 1;
	if (!leftover)
	{
		leftover = malloc(1);
		if (!leftover)
			return (NULL);
		leftover[0] = '\0';
	}
	while (!ft_strchr(leftover, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(leftover), NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		if (!temp)
			return (NULL);
		leftover = temp;
	}
	return (leftover);
}

static char	*extract_line(char *leftover)
{
	int		i;
	char	*line;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_memcpy(line, leftover, i);
	if (leftover[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_leftover(char *leftover)
{
	int		i;
	char	*new;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new = ft_strdup(leftover + i + 1);
	free(leftover);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd > 10240)
		return (NULL);
	leftover = read_and_store(fd, leftover);
	if (!leftover || !*leftover)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}