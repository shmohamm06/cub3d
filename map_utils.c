/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:02:20 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/12 19:24:21 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_texture_path(char **str, char **texture)
{
	if (*texture != NULL)
		return (-1);
	*texture = ft_strdup(str[1]);
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

int	fill_line(char **line, int size, char c)
{
	int		len;
	char	*filled_line;
	int		i;

	len = ft_strlen(*line);
	if (len >= size)
		return (0);
	filled_line = malloc(size + 1);
	if (filled_line == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		filled_line[i] = (*line)[i];
		i++;
	}
	while (i < size)
	{
		filled_line[i] = c;
		i++;
	}
	filled_line[i] = '\0';
	*line = filled_line;
	return (0);
}

int	fill_map(int fd, t_game *cub3d, int size_x, int i)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			if (ft_strlen(line) > 0)
				line[ft_strlen(line) - 1] = '\0';
			if (fill_line(&line, size_x, ' ') == -1)
			{
				free(line);
				free_2d(cub3d->map.blocks);
				return (-1);
			}
			cub3d->map.blocks[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	cub3d->map.blocks[i] = NULL;
	return (0);
}
