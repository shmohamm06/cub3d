/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:46:58 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 13:30:05 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_texture *image_data, int x, int y, int color)
{
	char	*dst;

	dst = image_data->address + (y * image_data->size_line + x
			* (image_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling(t_game *game, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&game->texture_data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->texture_data.img, 0,
		0);
}

void	draw_floor(t_game *cub3d, int color)
{
	int	y;
	int	x;

	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&cub3d->texture_data, x++, y, color);
		y++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture_data.img,
		0, 0);
}

void	clear_image(t_game *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			my_mlx_pixel_put(&cub3d->texture_data, x++, y, 0);
		++y;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture_data.img,
		0x000000, 0);
}

int	get_image_pixel(t_texture *texture, int x, int y)
{
	unsigned int	color;
	char			*dst;

	if (y <= 0)
	{
		y = 0;
	}
	dst = texture->address + (y * texture->size_line + (x
				* (texture->bits_per_pixel / 8)));
	color = *(unsigned int *)dst;
	return (color);
}
