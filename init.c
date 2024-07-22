/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:45:08 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/22 16:06:41 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
