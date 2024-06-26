/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:07:32 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/21 11:07:33 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	exit_g(v_game *game)
{
	int line;

	line = 0;
	mlx_destroy_window(game->mlx, game->window);
	if(game->map)
	{
		while (line < game->height)
		{
			free(game->map[line]);
			line++;
		}
	free(game->map);
	}
	free(game->mlx);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	v_game game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(v_game));
		if (!reading_map(&game, argv[1]))
			return (1);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, game.width * 40, game.height * 40, "So Long");
		img_location(&game);
		adding_graph(&game);
		mlx_hook(game.window, 17, 0, exit_g, NULL);
		mlx_loop(game.mlx);
	}
	else
		write(1, "Usage: ./so_long map.ber\n", 25);
	return (0);
}
