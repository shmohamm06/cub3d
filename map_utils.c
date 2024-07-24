/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:02:20 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/24 12:46:18 by shmohamm         ###   ########.fr       */
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

void	valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		printf("Invalid texture path\n");
		exit(1);
	}
}

int	map_empty(t_game *cub3d)
{
	if (cub3d->map.blocks == NULL)
		return (-1);
	return (0);
}

int	ignore_header(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		if (ft_strlen(line) > 1)
			i++;
	}
	return (0);
}

int	assign_map_coords(int fd, int *x, int *y)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			i = ft_strlen(line) - 1;
			if (i > *x)
				*x = i;
			(*y)++;
		}
		else if (*y > 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
