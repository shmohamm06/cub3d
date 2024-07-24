/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:23:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/24 12:52:32 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(char **str, char **texture)
{
	if (*texture != NULL)
		return (-1);
	*texture = ft_strdup(str[1]);
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

void	check_map(t_game *cub3d)
{
	if (map_empty(cub3d) == -1)
	{
		printf("Map is empty\n");
		exit(1);
	}
	if (check_contents(cub3d) == -1)
	{
		printf("Invalid Map\n");
		exit(1);
	}
	if (check_maps_sides(cub3d) == -1)
	{
		printf("Map sides are wrong\n");
		exit(1);
	}
	if (check_map_cont(cub3d) == -1)
		exit(1);
}
