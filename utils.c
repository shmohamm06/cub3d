/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/22 20:06:09 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	to_radians(float n)
{
	return (n * (PI / 180));
}

int	args_check(int ac)
{
	if (ac != 2)
	{
		printf("Incorrect amount of args bbg\n");
		exit(1);
	}
	return (0);
}

int	free_2d(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

int	free_path_texture(t_game *cub3d)
{
	if (cub3d->texture_paths.north != NULL)
		free(cub3d->texture_paths.north);
	if (cub3d->texture_paths.south != NULL)
		free(cub3d->texture_paths.south);
	if (cub3d->texture_paths.east != NULL)
		free(cub3d->texture_paths.east);
	if (cub3d->texture_paths.west != NULL)
		free(cub3d->texture_paths.west);
	return (0);
}
