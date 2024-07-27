/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:10:35 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/27 17:44:08 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_map(char *map, int *x, int *y)
{
	int	coords;
	int	fd;

	fd = open_map(map);
	if (fd == -1)
	{
		printf("Cannot open the map %s\n", map);
		exit(1);
	}
	if (ignore_header(fd) == -1)
	{
		printf("Error when parsing header %s\n", map);
		exit(1);
	}
	*x = 0;
	*y = 0;
	coords = assign_map_coords(fd, x, y);
	close(fd);
	return (coords);
}

int	map(char *map, t_game *cub3d)
{
	int	fd;
	int	parser;
	int	x;
	int	y;

	if (read_map(map, &x, &y) == -1)
		exit(1);
	fd = open_map(map);
	parser = parse_map(fd, cub3d, x, y);
	close(fd);
	if (parser == -1)
		return (-1);
	return (check_map(cub3d));
}
