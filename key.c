/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:53:50 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/13 11:51:16 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	release_textures(t_game *game, t_texture *textures)
{
	if (textures[NORTH].img)
		mlx_destroy_image(game->mlx, textures[NORTH].img);
	if (textures[SOUTH].img)
		mlx_destroy_image(game->mlx, textures[SOUTH].img);
	if (textures[WEST].img)
		mlx_destroy_image(game->mlx, textures[WEST].img);
	if (textures[EAST].img)
		mlx_destroy_image(game->mlx, textures[EAST].img);
}

int	terminate_game(t_game *game)
{
	if (game->map.blocks && game->map.blocks[0])
		free_2d(game->map.blocks);
	free_texture_paths(game);
	release_textures(game, game->textures);
	if (game->texture_data.img)
		mlx_destroy_image(game->mlx, game->texture_data.img);
	mlx_destroy_window(game->mlx, game->window);
	printf("GG and thanks for playing :-)\n");
	exit(0);
}

int	update_movement(t_game *game)
{
	if (game->input.turn_left)
		rotate_left(game);
	if (game->input.turn_right)
		rotate_right(game);
	if (game->input.up)
		move_player_forward(game);
	if (game->input.down)
		move_player_backward(game);
	if (game->input.right)
		strafe_player_right(game);
	if (game->input.left)
		strafe_player_left(game);
	render_scene(game);
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->input.up = true;
	else if (keycode == A_KEY)
		game->input.left = true;
	else if (keycode == S_KEY)
		game->input.down = true;
	else if (keycode == D_KEY)
		game->input.right = true;
	else if (keycode == LEFT)
		game->input.turn_left = true;
	else if (keycode == RIGHT)
		game->input.turn_right = true;
	update_movement(game);
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == ESC)
		terminate_game(game);
	else if (keycode == SHOW_MAP)
		game->display_map = !game->display_map;
	else if (keycode == W_KEY)
		game->input.up = false;
	else if (keycode == A_KEY)
		game->input.left = false;
	else if (keycode == S_KEY)
		game->input.down = false;
	else if (keycode == D_KEY)
		game->input.right = false;
	else if (keycode == LEFT)
		game->input.turn_left = false;
	else if (keycode == RIGHT)
		game->input.turn_right = false;
	return (0);
}
