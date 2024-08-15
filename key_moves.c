/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:52:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 17:19:25 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_forward(t_game *game)
{
	t_vector	new_pos;

	new_pos.x_coord = game->player.position.x_coord
		+ game->player.direction.x_coord * 0.35f;
	new_pos.y_coord = game->player.position.y_coord
		+ game->player.direction.y_coord * 0.35f;
	if (game->map.blocks[(int)game->player.position.y_coord]
		[(int)new_pos.x_coord] != '1')
		game->player.position.x_coord = new_pos.x_coord;
	if (game->map.blocks[(int)new_pos.y_coord]
		[(int)game->player.position.x_coord] != '1')
		game->player.position.y_coord = new_pos.y_coord;
}

void	move_player_backward(t_game *game)
{
	t_vector	new_pos;

	new_pos.x_coord = game->player.position.x_coord
		- game->player.direction.x_coord * 0.35f;
	new_pos.y_coord = game->player.position.y_coord
		- game->player.direction.y_coord * 0.35f;
	if (game->map.blocks[(int)game->player.position.y_coord]
		[(int)new_pos.x_coord] != '1')
		game->player.position.x_coord = new_pos.x_coord;
	if (game->map.blocks[(int)new_pos.y_coord]
		[(int)game->player.position.x_coord] != '1')
		game->player.position.y_coord = new_pos.y_coord;
}

void	strafe_player_right(t_game *game)
{
	float		angle;
	t_vector	strafe_dir;
	t_vector	new_pos;

	angle = to_radians(90);
	strafe_dir.x_coord = game->player.direction.x_coord * cos(angle)
		- game->player.direction.y_coord * sin(angle);
	strafe_dir.y_coord = game->player.direction.x_coord * sin(angle)
		+ game->player.direction.y_coord * cos(angle);
	new_pos.x_coord = game->player.position.x_coord + strafe_dir.x_coord * 0.35f;
	new_pos.y_coord = game->player.position.y_coord + strafe_dir.y_coord * 0.35f;
	if (game->map.blocks[(int)game->player.position.y_coord]
		[(int)new_pos.x_coord] != '1')
		game->player.position.x_coord = new_pos.x_coord;
	if (game->map.blocks[(int)new_pos.y_coord]
		[(int)game->player.position.x_coord] != '1')
		game->player.position.y_coord = new_pos.y_coord;
}

void	strafe_player_left(t_game *game)
{
	float		angle;
	t_vector	strafe_dir;
	t_vector	new_pos;

	angle = to_radians(-90);
	strafe_dir.x_coord = game->player.direction.x_coord * cos(angle)
		- game->player.direction.y_coord * sin(angle);
	strafe_dir.y_coord = game->player.direction.x_coord * sin(angle)
		+ game->player.direction.y_coord * cos(angle);
	new_pos.x_coord = game->player.position.x_coord + strafe_dir.x_coord * 0.35f;
	new_pos.y_coord = game->player.position.y_coord + strafe_dir.y_coord * 0.35f;
	if (game->map.blocks[(int)game->player.position.y_coord]
		[(int)new_pos.x_coord] != '1')
		game->player.position.x_coord = new_pos.x_coord;
	if (game->map.blocks[(int)new_pos.y_coord]
		[(int)game->player.position.x_coord] != '1')
		game->player.position.y_coord = new_pos.y_coord;
}
