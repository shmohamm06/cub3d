/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:44:40 by shmohamm          #+#    #+#             */
/*   Updated: 2025/05/16 16:06:22 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_file_type(char *str)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(str) - 4;
	if (i < 0 || ft_strncmp(".xpm", (str + i), 4 + 1))
		return (false);
	return (true);
}

bool	check_all_textures(t_game *cub3d)
{
	if (valid_file_path(cub3d->texture_paths.north) == -1)
		return (false);
	if (valid_file_path(cub3d->texture_paths.south) == -1)
		return (false);
	if (valid_file_path(cub3d->texture_paths.east) == -1)
		return (false);
	if (valid_file_path(cub3d->texture_paths.west) == -1)
		return (false);
	if (check_file_type(cub3d->texture_paths.north) == false)
		return (false);
	if (check_file_type(cub3d->texture_paths.south) == false)
		return (false);
	if (check_file_type(cub3d->texture_paths.east) == false)
		return (false);
	if (check_file_type(cub3d->texture_paths.west) == false)
		return (false);
	if (check_texture_conversion(cub3d) == false)
		return (false);
	return (true);
}


int	valid_file_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		printf("Invalid file path\n");
		return (-1);
	}
	return (0);
}

int	map_empty(t_game *cub3d)
{
	if (cub3d->map.blocks == NULL)
		return (-1);
	return (0);
}

int	open_map(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error when opening map\n");
		exit(1);
	}
	return (fd);
}
