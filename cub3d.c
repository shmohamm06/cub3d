/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:17:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/08/03 17:53:59 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void render_scene(t_game *game) {
    // Clear the window to prepare for a new frame
    mlx_clear_window(game->mlx_instance, game->window);

    // Set up input hooks to handle player actions
    setup_hooks(game);

    // Reset the image buffer to start with a clean slate
    clear_image(game);

    // Draw the ceiling and floor with the specified colors
    draw_ceiling(game, game->ceiling_col);
    draw_floor(game, game->floor_color);

    // Perform raycasting to calculate visible walls and render them
    raycast(game, game->textures);

    // Display the rendered frame on the window
    mlx_put_image_to_window(game->mlx_instance, game->window, game->texture_data.img, 0, 0);
}

// Setup input hooks for handling player actions and rendering
void setup_hooks(t_game *game) {
    // Hook for handling key press events
    mlx_hook(game->window, 2, (1L << 0), handle_key_press, game);

    // Hook for handling key release events
    mlx_hook(game->window, 3, (1L << 1), handle_key_release, game);

    // Hook for closing the window (e.g., clicking the close button)
    mlx_hook(game->window, 17, (1L << 17), terminate_game, game);

    // Hook for rendering the scene continuously in the game loop
    mlx_loop_hook(game->mlx_instance, render_scene, game);
}

int	main(int ac, char **av)
{
	t_game	cub3d;

	args_check(ac);
	init_data(&cub3d);
	map(av[1], &cub3d);
}
