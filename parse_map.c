/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:45:29 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/24 12:13:08 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(int fd, t_game *cub3d, int size_x, int size_y)
{
	cub3d->map.x = size_x;
	cub3d->map.y = size_y;
	cub3d->map.blocks = malloc(sizeof(char **) * (cub3d->map.y + 1));
	if (cub3d->map.blocks == NULL)
		return (-1);
	cub3d->map.block_size = 1;
	return (fill_map_blocks(fd, cub3d, size_x, 0));
}

int	parse_map_header(t_game *cub3d, char **spl, bool *floor, bool *ceiling)
{
	if (ft_strcmp(spl[0], "NO") == 0)
		return (load_texture(spl, &cub3d->texture_paths.north));
	if (ft_strcmp(spl[0], "SO") == 0)
		return (load_texture(spl, &cub3d->texture_paths.south));
	if (ft_strcmp(spl[0], "WE") == 0)
		return (load_texture(spl, &cub3d->texture_paths.west));
	if (ft_strcmp(spl[0], "EA") == 0)
		return (load_texture(spl, &cub3d->texture_paths.east));
	if (ft_strcmp(spl[0], "F") == 0)
	{
		if (*floor == true || parse_colour(spl[1], &cub3d->floor_color) == -1)
			return (-1);
		*floor = true;
		return (0);
	}
	if (ft_strcmp(spl[0], "C") == 0)
	{
		if (*ceiling == true || parse_colour(spl[1], &cub3d->ceiling_col) == -1)
			return (-1);
		*ceiling = true;
		return (0);
	}
	if (spl[0] != NULL && ft_strcmp(spl[0], "\n") == 0 && spl[1] == NULL)
		return (0);
	return (-1);
}

int	parse_header(int fd, t_game *cub3d, int flag)
{
	bool	floor;
	bool	ceiling;
	char	*line;
	char	**splitted;

	floor = false;
	ceiling = false;
	while ((cub3d->texture_paths.north == NULL
			|| cub3d->texture_paths.south == NULL
			|| cub3d->texture_paths.west == NULL
			|| cub3d->texture_paths.east == NULL || !floor || !ceiling)
		&& flag != -1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		splitted = remove_nl(line);
		free(line);
		if (splitted == NULL)
			return (-1);
		if (parse_map_header(cub3d, splitted, &floor, &ceiling) == -1)
			flag = -1;
		free_2d(splitted);
	}
	return (flag);
}
