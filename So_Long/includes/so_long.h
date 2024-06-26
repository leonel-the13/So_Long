/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:37:03 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/24 07:37:04 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../includes/get_next_line.h"
# include "../includes/mlx.h"
#include "../libft_score/libft.h"

typedef struct gm
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	*exit;
	void	*item;
	void	*wall;
	void	*player;
	char	**map;
	int 	fd;
	int		player_count;
	int		column_count;
	int 	exit_count;
	int		x_ax;
	int 	y_ax;
	int		count;
	int 	collectables;
	int		width;
	int		height;
}			v_game;

int	exit_g(v_game *game);
int	reading_map(v_game *game, char *map);
void img_location(v_game *game);
void adding_graph(v_game *game);


#endif
