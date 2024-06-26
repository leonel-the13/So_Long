/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:23:54 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/30 09:23:55 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*get_buffer(char *buffer, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		tmp[i] = '\0';
	i = 1;
	while (!ft_rchr(tmp, '\n') && i)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
			return (NULL);
		tmp[i] = '\0';
		if (!buffer)
			buffer = ft_dup(tmp);
		else
			buffer = ft_join(buffer, tmp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = get_buffer(buff, fd);
	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
		++i;
	if (buff[i] == '\n')
		++i;
	line = ft_sub(buff, 0, i);
	tmp = ft_sub(buff, i, ft_len(buff) - i);
	free(buff);
	buff = tmp;
	return (line);
}
