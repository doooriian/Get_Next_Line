/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:31 by doley             #+#    #+#             */
/*   Updated: 2024/10/19 17:41:01 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	
}