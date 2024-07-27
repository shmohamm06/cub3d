/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:44:40 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/27 17:40:10 by shmohamm         ###   ########.fr       */
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
	return (true);
}

int	load_texture(char **str, char **texture)
{
	if (*texture != NULL)
		return (-1);
	*texture = ft_strdup(str[1]);
	return (0);
}
