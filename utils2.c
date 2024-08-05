/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:03:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/05 14:31:09 by shmohamm         ###   ########.fr       */
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
