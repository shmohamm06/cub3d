/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:49 by shmohamm          #+#    #+#             */
/*   Updated: 2025/05/16 16:02:57 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	check_files_accessibility();
	init_data(&cub3d);
	map(av[1], &cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	begin_execution(&cub3d);
	mlx_loop(cub3d.mlx);
}
