/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:23:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/18 15:43:57 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_validity(t_game *cub3d, int y, int x)
{
	if (y > 0 && (cub3d->map.blocks[y - 1][x] != '1' && cub3d->map.blocks[y
			- 1][x] != ' '))
		return (-1);
	if (x > 0 && (cub3d->map.blocks[y][x - 1] != '1' && cub3d->map.blocks[y][x
		- 1] != ' '))
		return (-1);
	if (cub3d->map.blocks[y][x + 1] != '\0' && (cub3d->map.blocks[y][x
			+ 1] != '1' && cub3d->map.blocks[y][x + 1] != ' '))
		return (-1);
	if (cub3d->map.blocks[y + 1] != NULL && (cub3d->map.blocks[y + 1][x] != '1'
		&& cub3d->map.blocks[y + 1][x] != ' '))
		return (-1);
	return (0);
}

int	check_inside_map(t_game *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub3d->map.y)
	{
		x = 0;
		while (x < cub3d->map.x)
		{
			if (cub3d->map.blocks[y][x] == ' ')
			{
				if (check_map_validity(cub3d, y, x) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_contents(t_game *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map.blocks[i] != NULL)
	{
		j = 0;
		while (cub3d->map.blocks[i][j] != '\0')
		{
			if (cub3d->map.blocks[i][j] != '0' && cub3d->map.blocks[i][j] != ' '
				&& cub3d->map.blocks[i][j] != '1'
				&& cub3d->map.blocks[i][j] != 'N'
				&& cub3d->map.blocks[i][j] != 'S'
				&& cub3d->map.blocks[i][j] != 'W'
				&& cub3d->map.blocks[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_game *cub3d)
{
	check_and_exit(map_empty(cub3d), "Map is empty\n", 1);
	check_and_exit(check_contents(cub3d), "Invalid Contents in Map", 1);
	check_and_exit(check_maps_sides(cub3d), "Map sides are wrong\n", 1);
	check_and_exit(player_direction(cub3d, 0, 0, 0),
		"Invalid player position, can only be N, S, W, or E",
		1);
	check_and_exit(check_inside_map(cub3d), "Invalid Map structure\n", 1);
	check_and_exit(check_all_textures(cub3d), "Invalid Map structure\n", 1);
	return (0);
}
