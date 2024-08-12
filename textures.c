/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:54:14 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/12 19:34:10 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_xpms(t_game *cub3d, t_texture *tex, char *texture_path)
{
	void	*image;

	image = mlx_xpm_file_to_image(cub3d->mlx, texture_path, &tex->img_width,
			&tex->img_height);
	if (image == NULL)
	{
		printf("Error trying to open %s\n", texture_path);
		exit(1);
	}
}

void	init_tex(t_game *cub3d)
{
	init_tex_values(&cub3d->textures[NORTH]);
	init_tex_values(&cub3d->textures[SOUTH]);
	init_tex_values(&cub3d->textures[EAST]);
	init_tex_values(&cub3d->textures[WEST]);
}

void	init_tex_values(t_texture *texture)
{
	texture->img = NULL;
	texture->address = NULL;
	texture->bits_per_pixel = 0;
	texture->size_line = 0;
	texture->endian = 0;
	texture->img_width = 0;
	texture->img_height = 0;
	texture->texture_x = 0;
	texture->texture_y = 0;
}

void	fill_walls(t_game *cub3d, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub3d->mlx, path, &tex->img_width,
			&tex->img_height);
	if (!tex->img)
	{
		printf("texture mlx to image failed");
		return ;
	}
	tex->address = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
}

void	check_and_load_textures(t_game *cub3d)
{
	fill_walls(cub3d, &cub3d->textures[NORTH], cub3d->texture_paths.north);
	fill_walls(cub3d, &cub3d->textures[SOUTH], cub3d->texture_paths.south);
	fill_walls(cub3d, &cub3d->textures[EAST], cub3d->texture_paths.west);
	fill_walls(cub3d, &cub3d->textures[WEST], cub3d->texture_paths.east);
}
