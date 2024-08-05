/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:52:27 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 12:41:49 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_dimensions(t_game *game, t_ray_calc *ray_calc,
		t_wall_draw *wall_draw, t_texture *texture)
{
	wall_draw->line_length = (int)(WINDOW_SIZE_Y / ray_calc->wall_dist);
	wall_draw->start_draw = -wall_draw->line_length / 2 + WINDOW_SIZE_Y / 2;
	if (wall_draw->start_draw < 0)
		wall_draw->start_draw = 0;
	wall_draw->end_draw = wall_draw->line_length / 2 + WINDOW_SIZE_Y / 2;
	if (wall_draw->end_draw >= WINDOW_SIZE_Y)
		wall_draw->end_draw = WINDOW_SIZE_Y - 1;
	if (ray_calc->hit_side == 0)
		wall_draw->wall_hit_x = game->player.position.y_coord
			+ ray_calc->wall_dist * ray_calc->ray_dir.y_coord;
	else
		wall_draw->wall_hit_x = game->player.position.x_coord
			+ ray_calc->wall_dist * ray_calc->ray_dir.x_coord;
	wall_draw->wall_hit_x -= floor(wall_draw->wall_hit_x);
	wall_draw->texture_step = 1.0 * texture->img_height
		/ wall_draw->line_length;
	wall_draw->texture_position = (wall_draw->start_draw - WINDOW_SIZE_Y / 2
			+ wall_draw->line_length / 2) * wall_draw->texture_step;
}

void	render_wall_slice(t_game *game, t_ray_calc *ray_calc,
		t_texture *texture)
{
	t_wall_draw	wall_draw;
	int			y;
	int			color;
	int			texture_y;

	select_texture(game, ray_calc, texture);
	calculate_wall_dimensions(game, ray_calc, &wall_draw, texture);
	texture->texture_x = (int)(wall_draw.wall_hit_x
			* (float)texture->img_width);
	if (ray_calc->hit_side == 0 && ray_calc->ray_dir.x_coord > 0)
		texture->texture_x = texture->img_width - texture->texture_x - 1;
	if (ray_calc->hit_side == 1 && ray_calc->ray_dir.y_coord < 0)
		texture->texture_x = texture->img_width - texture->texture_x - 1;
	y = wall_draw.start_draw;
	while (y < wall_draw.end_draw)
	{
		texture_y = (int)wall_draw.texture_position & (texture->img_height - 1);
		color = get_image_pixel(texture, texture->texture_x, texture_y);
		draw_pixel(&game->texture_data, ray_calc->screen_x, y, color);
		wall_draw.texture_position += wall_draw.texture_step;
		y++;
	}
}

void	select_texture(t_game *cub3d, t_ray_calc *ray_calc, t_texture *texture)
{
	if (ray_calc->hit_side == 0)
	{
		if (ray_calc->ray_dir.x_coord > 0)
			*texture = cub3d->textures[EAST];
		else
			*texture = cub3d->textures[WEST];
	}
	else
	{
		if (ray_calc->ray_dir.y_coord > 0)
			*texture = cub3d->textures[SOUTH];
		else
			*texture = cub3d->textures[NORTH];
	}
}
