/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/06 11:38:28 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	to_radians(float degrees)
{
	return (degrees * (PI / 180.0f));
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

char	**remove_nl(char *line)
{
	char	**str;

	str = ft_split(line, ' ');
	if (str == NULL)
		return (NULL);
	if (str[0] != NULL && str[1] != NULL && ft_strlen(str[1]) >= 1
		&& str[1][ft_strlen(str[1]) - 1] == '\n')
		str[1][ft_strlen(str[1]) - 1] = '\0';
	return (str);
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

int	free_texture_paths(t_game *cub3d)
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
