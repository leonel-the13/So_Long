/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:24 by vleonel           #+#    #+#             */
/*   Updated: 2024/06/20 15:01:25 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx/mlx.h"
#include <stdlib.h>

int close_program(void *param)
{
	(void)param;
	exit(0);
}

int main(void)
{
    void *mlx_ptr, *win_ptr;
    void *img_ptr;
    int width, height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "So Long");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "img.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 400, 300);

    mlx_hook(win_ptr, 17, 0, close_program, NULL);

    mlx_loop(mlx_ptr);

    return 0;
}