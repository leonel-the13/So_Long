/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:49:07 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/28 12:49:08 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_top_bottom_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_putstr_fd("Error\n", 1);
            exit(1);
		}
		i++;
	}
}

static void	check_left_right_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_putstr_fd("Error\n", 1);
            exit(1);
		}
		i++;
	}
}

static void	check_interior(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 1)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && 
			    game->map[i][j] != 'E' && game->map[i][j] != 'C' && 
			    game->map[i][j] != 'P' && game->map[i][j] != '\n')
			{
				ft_putstr_fd("Error\n", 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

// static void check_way(t_game *game)
// {

// }

void	verify_error(t_game *game)
{
	check_top_bottom_borders(game);
	check_left_right_borders(game);
    check_interior(game);
}
