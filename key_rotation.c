/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:54:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 10:54:40 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game)
{
	float		rotation_speed;
	t_vector	new_view_plane;
	t_vector	new_direction;

	rotation_speed = -0.03f;
	new_direction.x_coord = game->player.direction.x_coord * cos(rotation_speed)
		- game->player.direction.y_coord * sin(rotation_speed);
	new_direction.y_coord = game->player.direction.x_coord * sin(rotation_speed)
		+ game->player.direction.y_coord * cos(rotation_speed);
	new_view_plane.x_coord = game->player.view_plane.x_coord
		* cos(rotation_speed) - game->player.view_plane.y_coord
		* sin(rotation_speed);
	new_view_plane.y_coord = game->player.view_plane.x_coord
		* sin(rotation_speed) + game->player.view_plane.y_coord
		* cos(rotation_speed);
	game->player.direction = new_direction;
	game->player.view_plane = new_view_plane;
}

void	rotate_right(t_game *game)
{
	float		rotation_speed;
	t_vector	new_view_plane;
	t_vector	new_direction;

	rotation_speed = 0.03f;
	new_direction.x_coord = game->player.direction.x_coord * cos(rotation_speed)
		- game->player.direction.y_coord * sin(rotation_speed);
	new_direction.y_coord = game->player.direction.x_coord * sin(rotation_speed)
		+ game->player.direction.y_coord * cos(rotation_speed);
	new_view_plane.x_coord = game->player.view_plane.x_coord
		* cos(rotation_speed) - game->player.view_plane.y_coord
		* sin(rotation_speed);
	new_view_plane.y_coord = game->player.view_plane.x_coord
		* sin(rotation_speed) + game->player.view_plane.y_coord
		* cos(rotation_speed);
	game->player.direction = new_direction;
	game->player.view_plane = new_view_plane;
}
