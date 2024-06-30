/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 07:51:05 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/27 07:51:09 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	may_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		write(1, "Parabens, Voce venceu!\n", 23);
		exit_g(game);
	}
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->collectables++;
		game->map[game->ax_y][game->ax_x] = '0';
		game->map[y][x] = 'P';
		game->ax_y = y;
		game->ax_x = x;
		game->player_count++;
	}
	return (1);
}

static int	move_up_and_down(t_game *game, int cmd)
{
	int	x;
	int	y;
	int	key;

	x = game->ax_x;
	y = game->ax_y;
	if (cmd == KEY_W)
		y--;
	else if (cmd == KEY_S)
		y++;
	key = may_move(game, x, y);
	ft_putstr_fd("Numero de passos: ", 1);
	ft_putnbr_fd(game->player_count, 1);
	write(1, "\n", 1);
	return (key);
}

static int	move_left_and_right(t_game *game, int cmd)
{
	int	x;
	int	y;
	int	key;

	x = game->ax_x;
	y = game->ax_y;
	if (cmd == KEY_A)
		x--;
	else if (cmd == KEY_D)
		x++;
	key = may_move(game, x, y);
	ft_putstr_fd("Numero de passos: ", 1);
	ft_putnbr_fd(game->player_count, 1);
	write(1, "\n", 1);
	return (key);
}

int	commands(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_g(game);
	else if (key == KEY_W || key == KEY_S)
		move_up_and_down(game, key);
	else if (key == KEY_A || key == KEY_D)
		move_left_and_right(game, key);
	if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
		adding_graph(game);
	return (1);
}
