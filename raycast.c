/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:00:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 14:08:18 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_one_ray(t_game *cub3d, int x, t_texture *texture)
{
	t_ray_calc	rc;

	init_racalc(cub3d, x, &rc);
	check_wall_hit(cub3d, &rc);
	calculate_distance_to_wall(&rc);
	render_wall_slice(cub3d, &rc, texture);
}

void	raycast(t_game *cub3d, t_texture *texture)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_one_ray(cub3d, x, texture);
		x++;
	}
}
