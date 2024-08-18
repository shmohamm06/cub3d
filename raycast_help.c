/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:58:44 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/18 15:19:30 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_game *cub3d, t_ray_calc *rc)
{
	bool	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_distance.x_coord < rc->side_distance.y_coord)
		{
			rc->side_distance.x_coord += rc->delta_distance.x_coord;
			rc->grid_pos.x_coord += rc->step_direction.x_coord;
			rc->hit_side = 0;
		}
		else
		{
			rc->side_distance.y_coord += rc->delta_distance.y_coord;
			rc->grid_pos.y_coord += rc->step_direction.y_coord;
			rc->hit_side = 1;
		}
		if (rc->grid_pos.y_coord < 0 || rc->grid_pos.x_coord < 0
			|| cub3d->map.blocks[(int)(rc->grid_pos.y_coord)]
				[(int)(rc->grid_pos.x_coord)] == '1')
			hit = 1;
	}
}

void	init_calc(t_game *cub3d, int x, t_ray_calc *rc)
{
	rc->screen_x = x;
	rc->camera_plane_x = 2 * rc->screen_x / (float)WIN_WIDTH - 1;
	rc->ray_dir = calculate_ray_direction(cub3d, rc->camera_plane_x);
	rc->delta_distance = calculate_delta_distance(&rc->ray_dir);
	rc->step_direction = calculate_step(&rc->ray_dir);
	rc->grid_pos.x_coord = (int)cub3d->player.position.x_coord;
	rc->grid_pos.y_coord = (int)cub3d->player.position.y_coord;
	rc->side_distance = calcsid(cub3d, &rc->ray_dir, &rc->grid_pos,
			&rc->delta_distance);
	rc->hit_side = 0;
}

void	calculate_distance_to_wall(t_ray_calc *ray_calc)
{
	if (ray_calc->hit_side == 0)
		ray_calc->wall_dist = ray_calc->side_distance.x_coord
			- ray_calc->delta_distance.x_coord;
	else
		ray_calc->wall_dist = ray_calc->side_distance.y_coord
			- ray_calc->delta_distance.y_coord;
}

void	pick_texture(t_game *cub3d, t_ray_calc *ray_calc, t_texture *texture)
{
	if (ray_calc->hit_side == 0)
	{
		if (ray_calc->ray_dir.x_coord < 0)
			*texture = cub3d->textures[EAST];
		else
			*texture = cub3d->textures[WEST];
	}
	else
	{
		if (ray_calc->ray_dir.y_coord < 0)
			*texture = cub3d->textures[SOUTH];
		else
			*texture = cub3d->textures[NORTH];
	}
}
