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
# define SO_LONG_H

# include "../includes/get_next_line.h"
# include "../includes/mlx.h"
# include "../libft_score/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 42

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
	int		fd;
	int		player_count;
	int		ax_x;
	int		ax_y;
	int		collectables;
	int		width;
	int		height;
}			t_game;

# ifdef __linux__
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_ESC 65307
# endif

int			exit_g(t_game *game);
int			reading_map(t_game *game, char *map);
int			commands(int key, t_game *game);
void		verify_error(t_game *game);
void		img_location(t_game *game);
void		adding_graph(t_game *game);

#endif
