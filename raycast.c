/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:00:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 14:19:58 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_single_ray(t_game *game, int screen_x)
{
	t_ray_calc	ray_calc;

	initialize_ray_calculation(game, screen_x, &ray_calc);
	perform_dda(game, &ray_calc);
	calculate_wall_distance(&ray_calc);
	render_wall_slice(game, &ray_calc, &game->texture_data);
}

void	perform_raycasting(t_game *game)
{
	int	screen_x;

	screen_x = 0;
	while (screen_x < WINDOW_SIZE_X)
	{
		cast_single_ray(game, screen_x);
		screen_x++;
	}
}
