/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:55:21 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 14:19:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	calculate_ray_direction(t_gamer *player, float camera_plane_x)
{
	t_vector	ray_direction;

	ray_direction.x_coord = player->direction.x_coord
		+ player->view_plane.x_coord * camera_plane_x;
	ray_direction.y_coord = player->direction.y_coord
		+ player->view_plane.y_coord * camera_plane_x;
	return (ray_direction);
}

t_vector	calculate_delta_distance(t_vector *ray_direction)
{
	t_vector	delta_distance;

	delta_distance.x_coord = fabs(1.0 / ray_direction->x_coord);
	delta_distance.y_coord = fabs(1.0 / ray_direction->y_coord);
	return (delta_distance);
}

t_vector	calculate_step_direction(t_vector *ray_direction)
{
	t_vector	step_direction;

	if (ray_direction->x_coord < 0)
		step_direction.x_coord = -1;
	else
		step_direction.x_coord = 1;
	if (ray_direction->y_coord < 0)
		step_direction.y_coord = -1;
	else
		step_direction.y_coord = 1;
	return (step_direction);
}

t_vector	calculate_initial_side_distance(t_gamer *player,
											t_vector *ray_direction,
											t_vector *grid_pos,
											t_vector *delta_distance)
{
	t_vector	side_distance;

	if (ray_direction->x_coord < 0)
	{
		side_distance.x_coord = (player->position.x_coord - grid_pos->x_coord)
			* delta_distance->x_coord;
	}
	else
	{
		side_distance.x_coord = (grid_pos->x_coord + 1.0
				- player->position.x_coord) * delta_distance->x_coord;
	}
	if (ray_direction->y_coord < 0)
	{
		side_distance.y_coord = (player->position.y_coord - grid_pos->y_coord)
			* delta_distance->y_coord;
	}
	else
	{
		side_distance.y_coord = (grid_pos->y_coord + 1.0
				- player->position.y_coord) * delta_distance->y_coord;
	}
	return (side_distance);
}
