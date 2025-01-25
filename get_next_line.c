/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:24:50 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/21 10:25:17 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*keep_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

char	*get_ret_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read_fd(int fd, char *stash, ssize_t read_bytes)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), NULL);
		if (read_bytes == 0 && (!stash || *stash == '\0'))
			break ;
		buff[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		if (!stash)
			return (NULL);
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		read_bytes;

	read_bytes = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_fd(fd, stash, read_bytes);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = get_ret_line(stash);
	if (!line || *line == '\0')
		return (free(line), free(stash), NULL);
	stash = keep_stash(stash);
	if (stash && *stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}