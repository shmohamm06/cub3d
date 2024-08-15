/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/15 14:35:11 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_exit(int condition, const char *message, int exit_code)
{
	if (condition == -1)
	{
		printf("%s\n", message);
		exit(exit_code);
	}
}

int	parse_colour(char *colour, int *hex_colour)
{
	char	**str;
	int		nb;
	int		i;

	if (colour == NULL)
		return (-1);
	str = ft_split(colour, ',');
	if (str == NULL || str[0] == NULL || str[1] == NULL || str[2] == NULL)
		return (-1);
	*hex_colour = 0;
	i = 0;
	while (i < 3)
	{
		nb = ft_atoi(str[i]);
		if (nb < 0 || nb > 255)
			return (-1);
		*hex_colour = *hex_colour | ft_atoi(str[i]) << (2 - i) * 8;
		i++;
	}
	return (0);
}

void	check_plane(t_game *cub3d)
{
	if (cub3d->player_initial_pos == 'N')
	{
		cub3d->player.view_plane.x_coord = 0.66;
		cub3d->player.view_plane.y_coord = 0;
	}
	if (cub3d->player_initial_pos == 'S')
	{
		cub3d->player.view_plane.x_coord = -0.66;
		cub3d->player.view_plane.y_coord = 0;
	}
	if (cub3d->player_initial_pos == 'E')
	{
		cub3d->player.view_plane.x_coord = 0;
		cub3d->player.view_plane.y_coord = 0.66;
	}
	if (cub3d->player_initial_pos == 'W')
	{
		cub3d->player.view_plane.x_coord = 0;
		cub3d->player.view_plane.y_coord = -0.66;
	}
}

void	check_player_direction(t_game *cub3d)
{
	if (cub3d->player_initial_pos == 'N')
	{
		cub3d->player.direction.x_coord = 0;
		cub3d->player.direction.y_coord = -1;
	}
	if (cub3d->player_initial_pos == 'S')
	{
		cub3d->player.direction.x_coord = 0;
		cub3d->player.direction.y_coord = 1;
	}
	if (cub3d->player_initial_pos == 'E')
	{
		cub3d->player.direction.x_coord = 1;
		cub3d->player.direction.y_coord = 0;
	}
	if (cub3d->player_initial_pos == 'W')
	{
		cub3d->player.direction.x_coord = -1;
		cub3d->player.direction.y_coord = 0;
	}
}

void	check_files_accessibility(void)
{
	const char	*files[] = {
		"bigger.cub",
		"brick_wall.xpm",
		"brick_wall_cracked.xpm",
		"dehydrated_earth.xpm",
		"dirty_mossy_tiles.xpm"};
	int			file_count;
	int			i;

	file_count = 5;
	i = 0;
	while (i < file_count)
	{
		if (access(files[i], R_OK) != 0)
		{
			printf("Error trying to open %s\n", files[i]);
			exit(1);
		}
		i++;
	}
}
