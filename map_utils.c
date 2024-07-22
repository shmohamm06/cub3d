/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:23:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/22 19:26:24 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_empty(t_game *cub3d)
{
	if (cub3d->map.blocks == NULL)
		return (-1);
	return (0);
}

int	check_validity(t_game *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map.blocks[i] != NULL)
	{
		j = 0;
		while (cub3d->map.blocks[i][j] != '\0')
		{
			if (cub3d->map.blocks[i][j] != '0' &&
				cub3d->map.blocks[i][j] != ' ' &&
				cub3d->map.blocks[i][j] != '1' &&
				cub3d->map.blocks[i][j] != 'N' &&
				cub3d->map.blocks[i][j] != 'S' &&
				cub3d->map.blocks[i][j] != 'W' &&
				cub3d->map.blocks[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
