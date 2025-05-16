/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:54:14 by shmohamm          #+#    #+#             */
/*   Updated: 2025/05/16 16:10:26 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	check_texture_conversion(t_game *cub3d)
{
	void	*tmp_img;
	int		width;
	int		height;

	char *paths[] = {
		cub3d->texture_paths.north,
		cub3d->texture_paths.south,
		cub3d->texture_paths.east,
		cub3d->texture_paths.west
	};

	for (int i = 0; i < 4; i++)
	{
		tmp_img = mlx_xpm_file_to_image(cub3d->mlx, paths[i], &width, &height);
		if (!tmp_img)
		{
			printf("Texture conversion failed for: %s\n", paths[i]);
			printf("Exiting program\n");
			exit(1);
			return (false);
		}
		mlx_destroy_image(cub3d->mlx, tmp_img); // Free it immediately
	}
	return (true);
}


void	fill_walls(t_game *cub3d, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub3d->mlx, path, &tex->img_width,
			&tex->img_height);
	if (!tex->img)
	{
		printf("Error trying to convert %s\n", path);
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
