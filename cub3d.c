/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/08 11:59:14 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_scene(t_game *cub3d)
{
	mlx_clear_window(cub3d->mlx, cub3d->window);
	setup_hooks(cub3d);
	clear_image(cub3d);
	draw_ceiling(cub3d, cub3d->ceiling_col);
	draw_floor(cub3d, cub3d->floor_color);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture_data.img,
		0, 0);
	return (0);
}
// raycast(game, game->textures);

void	setup_hooks(t_game *cub3d)
{
	mlx_hook(cub3d->window, 2, (1L << 0), handle_key_press, cub3d);
	mlx_hook(cub3d->window, 3, (1L << 1), handle_key_release, cub3d);
	mlx_hook(cub3d->window, 17, (1L << 17), terminate_game, cub3d);
	mlx_loop_hook(cub3d->mlx, render_scene, cub3d);
}

int	main(int ac, char **av)
{
	t_game	cub3d;

	args_check(ac);
	init_data(&cub3d);
	map(av[1], &cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	mlx_loop(cub3d.mlx);
}
