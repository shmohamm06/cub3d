/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:28:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/27 17:38:47 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
