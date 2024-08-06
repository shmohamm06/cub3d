/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/06 11:52:06 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_scene(t_game *game)
{
	mlx_clear_window(game->mlx_instance, game->window);
	setup_hooks(game);
	clear_image(game);
	draw_ceiling(game, game->ceiling_col);
	draw_floor(game, game->floor_color);
	mlx_put_image_to_window(game->mlx_instance, game->window,
		game->texture_data.img, 0, 0);
	return (0);
}
// raycast(game, game->textures);

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 2, (1L << 0), handle_key_press, game);
	mlx_hook(game->window, 3, (1L << 1), handle_key_release, game);
	mlx_hook(game->window, 17, (1L << 17), terminate_game, game);
	mlx_loop_hook(game->mlx_instance, render_scene, game);
}

int	main(int ac, char **av)
{
	t_game	cub3d;

	args_check(ac);
	init_data(&cub3d);
	map(av[1], &cub3d);
}
