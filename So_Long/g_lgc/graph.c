/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:56:35 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/24 07:56:36 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_location(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player, width * 40,
		height * 40);
	game->ax_y = height;
	game->ax_x = width;
}

void	collectables_location(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->item, width * 40,
		height * 40);
	game->collectables++;
}

void	img_location(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./g_img/floor.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./g_img/exit.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlx, "./g_img/item.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./g_img/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx, "./g_img/player.xpm", &i,
			&j);
}

void	verify_moves(t_game *game, int j, int i)
{
	if ((char)game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, i * 40, j
			* 40);
	else if ((char)game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, i * 40, j
			* 40);
	else if ((char)game->map[j][i] == 'C')
	{
		collectables_location(game, j, i);
		mlx_put_image_to_window(game->mlx, game->window, game->item, i * 40, j
			* 40);
	}
	else if ((char)game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, i * 40, j
			* 40);
	else if ((char)game->map[j][i] == 'P')
	{
		player_location(game, j, i);
		mlx_put_image_to_window(game->mlx, game->window, game->player, i * 40, j
			* 40);
	}
}

void	adding_graph(t_game *game)
{
	int	width;
	int	height;

	game->collectables = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			verify_moves(game, height, width);
			width++;
		}
		height++;
	}
}
