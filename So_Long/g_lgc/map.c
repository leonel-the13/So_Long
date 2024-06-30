/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:49:27 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/22 07:49:29 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	game->height++;
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		return (0);
	while (i < game->height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	tmp[game->height] = NULL;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

int	reading_map(t_game *game, char *map)
{
	char	*rd_map;

	game->fd = open(map, O_RDONLY);
	rd_map = get_next_line(game->fd);
	while (rd_map != NULL)
	{
		if (!add_line(game, rd_map))
		{
			free(rd_map);
			break ;
		}
		rd_map = get_next_line(game->fd);
	}
	close(game->fd);
	game->width = map_width(game->map[0]);
	return (1);
}
