/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:45:08 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 13:37:58 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	begin_execution(t_game *cub3d)
{
	check_plane(cub3d);
	check_player_direction(cub3d);
	create_image(cub3d);
	keys(cub3d);
	init_tex(cub3d);
	check_and_load_textures(cub3d);
	render_scene(cub3d);
}

int	render_scene(t_game *cub3d)
{
	t_texture	img;

	mlx_clear_window(cub3d->mlx, cub3d->window);
	setup_hooks(cub3d);
	clear_image(cub3d);
	draw_ceiling(cub3d, cub3d->ceiling_col);
	draw_floor(cub3d, cub3d->floor_color);
	raycast(cub3d, &img);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture_data.img,
		0, 0);
	return (0);
}

void	keys(t_game *cub3d)
{
	cub3d->input.up = 0;
	cub3d->input.down = 0;
	cub3d->input.left = 0;
	cub3d->input.right = 0;
	cub3d->input.turn_left = 0;
	cub3d->input.turn_right = 0;
}

void	create_image(t_game *cub3d)
{
	cub3d->texture_data.img = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub3d->texture_data.address = mlx_get_data_addr(cub3d->texture_data.img,
			&cub3d->texture_data.bits_per_pixel,
			&cub3d->texture_data.size_line,
			&cub3d->texture_data.endian);
}

void	init_data(t_game *cub3d)
{
	cub3d->map.x = 0;
	cub3d->map.y = 0;
	cub3d->map.block_size = 1;
	cub3d->player.rotation_angle = to_radians(0);
	cub3d->player.position.x_coord = 5;
	cub3d->player.position.y_coord = 5;
	cub3d->player.direction.x_coord = -1;
	cub3d->player.direction.y_coord = 0;
	cub3d->player.view_plane.x_coord = 0;
	cub3d->player.view_plane.y_coord = -0.66;
	cub3d->texture_paths.north = NULL;
	cub3d->texture_paths.south = NULL;
	cub3d->texture_paths.west = NULL;
	cub3d->texture_paths.east = NULL;
}
