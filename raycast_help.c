#include "cub3d.h"

// Perform DDA algorithm to find wall hit
void perform_dda(t_game *game, t_ray_calc *ray_calc) {
    bool hit = false;

    while (!hit) {
        // Move to the next grid square in the ray's path
        if (ray_calc->side_distance.x_coord < ray_calc->side_distance.y_coord) {
            ray_calc->side_distance.x_coord += ray_calc->delta_distance.x_coord;
            ray_calc->grid_pos.x_coord += ray_calc->step_direction.x_coord;
            ray_calc->hit_side = 0;
        } else {
            ray_calc->side_distance.y_coord += ray_calc->delta_distance.y_coord;
            ray_calc->grid_pos.y_coord += ray_calc->step_direction.y_coord;
            ray_calc->hit_side = 1;
        }

        // Check if the ray has hit a wall
        if (game->map.blocks[(int)ray_calc->grid_pos.y_coord][(int)ray_calc->grid_pos.x_coord] == '1') {
            hit = true;
        }
    }
}

// Initialize ray calculation parameters for a given column
void initialize_ray_calculation(t_game *game, int screen_x, t_ray_calc *ray_calc) {
    ray_calc->screen_x = screen_x;
    ray_calc->camera_plane_x = 2 * screen_x / (float)WINDOW_SIZE_X - 1;

    // Calculate ray direction based on player's direction and view plane
    ray_calc->ray_dir = calculate_ray_direction(&game->player, ray_calc->camera_plane_x);

    // Calculate delta distance for DDA
    ray_calc->delta_distance = calculate_delta_distance(&ray_calc->ray_dir);

    // Determine initial grid position and step direction
    ray_calc->grid_pos.x_coord = (int)game->player.position.x_coord;
    ray_calc->grid_pos.y_coord = (int)game->player.position.y_coord;
    ray_calc->step_direction = calculate_step_direction(&ray_calc->ray_dir);

    // Calculate initial side distance
    ray_calc->side_distance = calculate_initial_side_distance(&game->player, &ray_calc->ray_dir, &ray_calc->grid_pos, &ray_calc->delta_distance);

    ray_calc->hit_side = 0;
}

// Calculate the perpendicular distance to the wall hit
void calculate_wall_distance(t_ray_calc *ray_calc) {
    if (ray_calc->hit_side == 0) {
        ray_calc->wall_dist = ray_calc->side_distance.x_coord - ray_calc->delta_distance.x_coord;
    } else {
        ray_calc->wall_dist = ray_calc->side_distance.y_coord - ray_calc->delta_distance.y_coord;
    }
}
