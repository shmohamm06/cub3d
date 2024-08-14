/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:10:35 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/13 12:15:26 by shmohamm         ###   ########.fr       */
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
	int	x;
	int	y;

	read_map(map, &x, &y);
	fd = open_map(map);
	check_and_exit(parse_header(fd, cub3d, 0), "Parsing error in header\n", 1);
	check_and_exit(parse_map(fd, cub3d, x, y), "Parsing error in map\n", 1);
	close(fd);
	return (check_map(cub3d));
}
