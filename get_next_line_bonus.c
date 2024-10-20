/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:31 by doley             #+#    #+#             */
/*   Updated: 2024/10/20 18:15:07 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_fd_node(t_fd_list **fd_list, int fd)
{
	t_fd_list	*prev;
	t_fd_list	*current;

	prev = NULL;
	current = *fd_list;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*fd_list = current->next;
			if (current->stock)
				free(current->stock);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

t_fd_list	*get_fd_node(t_fd_list **fd_list, int fd)
{
	t_fd_list	*current;

	current = *fd_list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(t_fd_list));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->stock = NULL;
	current->next = *fd_list;
	*fd_list = current;
	return (current);
}

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
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!stock)
		return (NULL);
	line[i + 1] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list = NULL;
	t_fd_list			*current_fd;
	char				*buffer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_fd = get_fd_node(&fd_list, fd);
	if (!current_fd)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, &(current_fd->stock));
	free(buffer);
	if (!line)
	{
		free_fd_node(&fd_list, fd);
		return (NULL);
	}
	current_fd->stock = ft_trim(line);
	if (!current_fd->stock)
		free_fd_node(&fd_list, fd);
	return (line);
}
