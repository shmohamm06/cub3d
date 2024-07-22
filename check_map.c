/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:10:35 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/22 19:56:30 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_map(char *map, int *x, int *y)
{
	int	ret;
	int	fd;

	fd = open_map(map);
	if (fd == -1)
	{
		printf("Cannot open the map %s\n", map);
		return (-1);
	}
	if (ignore_header(fd) == -1)
		return (-1);
	*x = 0;
	*y = 0;
	ret = assign_map_coords(fd, x, y);
	close(fd);
	return (ret);
}

int	check_map(char *map, t_game *cub3d)
{
	int	fd;
	int	parser;
	int	x;
	int	y;

	if (read_map(map, &x, &y) == -1)
		return (-1);
	fd = open_map(map);
}
