/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:23:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/27 17:44:35 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_empty(t_game *cub3d)
{
	if (cub3d->map.blocks == NULL)
		return (-1);
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
	check_and_exit(check_contents(cub3d), "Invalid Contents in Map\n", 1);
	check_and_exit(check_maps_sides(cub3d), "Map sides are wrong\n", 1);
	check_and_exit(player_direction(cub3d, 0, 0, 0),
		"Invalid player position\n", 1);
	check_and_exit(check_inside_map(cub3d), "Invalid Map structure\n", 1);
	check_and_exit(check_all_textures(cub3d), "Invalid Map structure\n", 1);
	return (0);
}
