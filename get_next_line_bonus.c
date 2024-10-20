/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:31 by doley             #+#    #+#             */
/*   Updated: 2024/10/20 16:13:17 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_fd_list	*find_fd(int fd, t_fd_list *fd_list)
{
	t_fd_list	*new;
	
	while (fd_list->next)
	{
		if (fd_list->fd == fd)
			return (fd_list);
		fd_list = fd_list->next;
	}
	new->fd = fd;
	new->stock = NULL;
	new->next = NULL;
	fd_list->next = new;
	return (new);
}

char	*ft_read(int fd, char *buffer, char **stock)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (*stock);
			*stock = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[BUFFER_SIZE] = '\0';
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

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*current_fd;
	char				*buffer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_fd = find_fd(fd, fd_list);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, &current_fd->stock);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	current_fd->stock = ft_trim(line);
	return (line);
}
