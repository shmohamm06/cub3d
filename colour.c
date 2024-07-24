/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:17:09 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/24 12:04:11 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
