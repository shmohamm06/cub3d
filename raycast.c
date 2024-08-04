#include "cub3d.h"

// Perform raycasting and draw the wall slice for a given screen column
void cast_single_ray(t_game *game, int screen_x) {
    t_ray_calc ray_calc;

    // Initialize ray calculation parameters for this column
    initialize_ray_calculation(game, screen_x, &ray_calc);

    // Perform DDA to find where the ray hits a wall
    perform_dda(game, &ray_calc);

    // Calculate the distance from the player to the wall hit
    calculate_wall_distance(&ray_calc);

    // Draw the wall slice for this column
    render_wall_slice(game, &ray_calc, &game->texture_data);
}

// Perform raycasting for all screen columns
void perform_raycasting(t_game *game) {
    int screen_x;

    // Loop through each vertical slice of the screen
    for (screen_x = 0; screen_x < WINDOW_SIZE_X; screen_x++) {
        // Cast a single ray and render the wall slice
        cast_single_ray(game, screen_x);
    }
}
