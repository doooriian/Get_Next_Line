/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:29:37 by doley             #+#    #+#             */
/*   Updated: 2024/10/18 15:54:11 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, char **stock)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*stock);
			*stock = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!*stock)
			*stock = ft_strdup("");
		tmp = *stock;
		*stock = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(*stock, '\n'))
			break ;
	}
	return (*stock);
}

char	*ft_trim(char *line)
{
	size_t	i;
	char	*stock;

	i = 0;
	stock = NULL;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	if (line[i] == '\n' && line[i + 1] != '\0')
	{
		stock = ft_substr(line, i + 1, ft_strlen(line) - 1);
		if (!stock)
			return (NULL);
		line[i + 1] = '\0';
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stock)
			free(stock);
		stock = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, &stock);
	free(buffer);
	if (!line)
	{
		if (stock)
			free(stock);
		stock = NULL;
		return (NULL);
	}
	stock = ft_trim(line);
	return (line);
}
