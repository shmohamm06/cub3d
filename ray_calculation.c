/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:55:21 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 13:55:33 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	calculate_ray_direction(t_game *cub3d, float camera_x)
{
	t_vector	ray_direction;

	ray_direction.x_coord = cub3d->player.direction.x_coord
		+ cub3d->player.view_plane.x_coord * camera_x;
	ray_direction.y_coord = cub3d->player.direction.y_coord
		+ cub3d->player.view_plane.y_coord * camera_x;
	return (ray_direction);
}

// length of ray from one x or y-side to next x or y-side
t_vector	calculate_delta_distance(t_vector *ray_direction)
{
	t_vector	delta_dist;

	delta_dist.x_coord = fabs(1. / ray_direction->x_coord);
	delta_dist.y_coord = fabs(1. / ray_direction->y_coord);
	return (delta_dist);
}

t_vector	calculate_step(t_vector *ray_direction)
{
	t_vector	step;

	if (ray_direction->x_coord < 0)
		step.x_coord = -1;
	else
		step.x_coord = 1;
	if (ray_direction->y_coord < 0)
		step.y_coord = -1;
	else
		step.y_coord = 1;
	return (step);
}

t_vector	calcsid(t_game *cub3d, t_vector *rayd, t_vector *map,
		t_vector *deltd)
{
	t_vector	side_dist;

	if (rayd->x_coord < 0)
		side_dist.x_coord = (cub3d->player.position.x_coord - map->x_coord)
			* deltd->x_coord;
	else
		side_dist.x_coord = (map->x_coord + 1.0
				- cub3d->player.position.x_coord) * deltd->x_coord;
	if (rayd->y_coord < 0)
		side_dist.y_coord = (cub3d->player.position.y_coord - map->y_coord)
			* deltd->y_coord;
	else
		side_dist.y_coord = (map->y_coord + 1.0
				- cub3d->player.position.y_coord) * deltd->y_coord;
	return (side_dist);
}
