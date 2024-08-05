/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:58:44 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 11:00:29 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_game *game, t_ray_calc *ray_calc)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (ray_calc->side_distance.x_coord < ray_calc->side_distance.y_coord)
		{
			ray_calc->side_distance.x_coord += ray_calc->delta_distance.x_coord;
			ray_calc->grid_pos.x_coord += ray_calc->step_direction.x_coord;
			ray_calc->hit_side = 0;
		}
		else
		{
			ray_calc->side_distance.y_coord += ray_calc->delta_distance.y_coord;
			ray_calc->grid_pos.y_coord += ray_calc->step_direction.y_coord;
			ray_calc->hit_side = 1;
		}
		if (game->map.blocks[(int)ray_calc->grid_pos.y_coord]
			[(int)ray_calc->grid_pos.x_coord] == '1')
		{
			hit = true;
		}
	}
}

void	initialize_ray_calculation(t_game *game, int screen_x,
		t_ray_calc *ray_calc)
{
	ray_calc->screen_x = screen_x;
	ray_calc->camera_plane_x = 2 * screen_x / (float)WINDOW_SIZE_X - 1;
	ray_calc->ray_dir = calculate_ray_direction(&game->player,
			ray_calc->camera_plane_x);
	ray_calc->delta_distance = calculate_delta_distance(&ray_calc->ray_dir);
	ray_calc->grid_pos.x_coord = (int)game->player.position.x_coord;
	ray_calc->grid_pos.y_coord = (int)game->player.position.y_coord;
	ray_calc->step_direction = calculate_step_direction(&ray_calc->ray_dir);
	ray_calc->side_distance = calculate_initial_side_distance(&game->player,
			&ray_calc->ray_dir,
			&ray_calc->grid_pos,
			&ray_calc->delta_distance);
	ray_calc->hit_side = 0;
}

void	calculate_wall_distance(t_ray_calc *ray_calc)
{
	if (ray_calc->hit_side == 0)
	{
		ray_calc->wall_dist = ray_calc->side_distance.x_coord
			- ray_calc->delta_distance.x_coord;
	}
	else
	{
		ray_calc->wall_dist = ray_calc->side_distance.y_coord
			- ray_calc->delta_distance.y_coord;
	}
}
