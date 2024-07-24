/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:14:04 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/24 12:49:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_top_and_bottom(t_game *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.blocks[0][i] != ' ')
		i++;
	while (cub3d->map.blocks[0][i] != '\0')
	{
		if (cub3d->map.blocks[0][i] != '1' || cub3d->map.blocks[0][i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	check_horizontal(t_game *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map.y)
	{
		j = 0;
		while (cub3d->map.blocks[i][j] == ' ')
			j++;
		if (cub3d->map.blocks[i][j] != '1')
			return (-1);
		j = cub3d->map.x - 1;
		while (j >= 0 && cub3d->map.blocks[i][j] == ' ')
			j--;
		if (cub3d->map.blocks[i][j] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_vertical(t_game *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map.x)
	{
		j = 0;
		while (cub3d->map.blocks[j] != NULL && cub3d->map.blocks[j][i] == ' ')
			j++;
		if (cub3d->map.blocks[j] == NULL || cub3d->map.blocks[j][i] != '1')
			return (-1);
		j = cub3d->map.y - 1;
		while (cub3d->map.blocks[j] != NULL && cub3d->map.blocks[j][i] == ' ')
			j--;
		if (cub3d->map.blocks[j] == NULL || cub3d->map.blocks[j][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_maps_sides(t_game *cub3d)
{
	if (check_horizontal(cub3d) == -1)
		return (-1);
	if (check_vertical(cub3d) == -1)
		return (-1);
	return (0);
}
