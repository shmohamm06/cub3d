/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 12:43:18 by shmohamm         ###   ########.fr       */
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

int	free_2d(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (-1);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
