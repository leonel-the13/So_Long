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

int	exit_g(t_game *game)
{
	int	line;

	line = 0;
	mlx_destroy_window(game->mlx, game->window);
	if (game->map)
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		reading_map(&game, argv[1]);
		verify_error(&game);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, game.width * 40, game.height
				* 40, "So Long");
		img_location(&game);
		adding_graph(&game);
		mlx_key_hook(game.window, commands, &game);
		mlx_hook(game.window, 17, 1L << 0, exit_g, &game);
		mlx_loop(game.mlx);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
