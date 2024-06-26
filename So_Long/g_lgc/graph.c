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

void player_location(v_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player, width * 40, height * 40);
	game->y_ax = height;
	game->x_ax = width;
}

void collectables_location(v_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->window, game->item, width * 40, height * 40);
	game->collectables++;
}

void img_location(v_game *game)
{
	int i;
	int j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./g_img/floor.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./g_img/exit.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlx, "./g_img/item.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./g_img/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx, "./g_img/player.xpm", &i, &j);
}

void adding_graph(v_game *game)
{
	int width;
	int height;

	game->collectables = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			printf("%c", game->map[height][width]);
			if((char)game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor, width * 40, height * 40);
			else if((char)game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, width * 40, height * 40);
			else if((char)game->map[height][width] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->item, width * 40, height * 40);
			else if((char)game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, width * 40, height * 40);
			else if((char)game->map[height][width] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, width * 40, height * 40);
			width++;
		}
		printf("\n");
		height++;
	}
}
