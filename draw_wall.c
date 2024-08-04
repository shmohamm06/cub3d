#include "cub3d.h"

// Calculate wall slice dimensions and texture coordinates
void calculate_wall_dimensions(t_game *game, t_ray_calc *ray_calc, t_wall_draw *wall_draw, t_texture *texture) {
    // Calculate line height based on wall distance
    wall_draw->line_length = (int)(WINDOW_SIZE_Y / ray_calc->wall_dist);
    
    // Determine where to start drawing the wall slice
    wall_draw->start_draw = -wall_draw->line_length / 2 + WINDOW_SIZE_Y / 2;
    if (wall_draw->start_draw < 0)
        wall_draw->start_draw = 0;
    
    // Determine where to stop drawing the wall slice
    wall_draw->end_draw = wall_draw->line_length / 2 + WINDOW_SIZE_Y / 2;
    if (wall_draw->end_draw >= WINDOW_SIZE_Y)
        wall_draw->end_draw = WINDOW_SIZE_Y - 1;
    
    // Calculate the exact position of the wall hit
    if (ray_calc->hit_side == 0)
        wall_draw->wall_hit_x = game->player.position.y_coord + ray_calc->wall_dist * ray_calc->ray_dir.y_coord;
    else
        wall_draw->wall_hit_x = game->player.position.x_coord + ray_calc->wall_dist * ray_calc->ray_dir.x_coord;
    
    // Normalize wall hit position
    wall_draw->wall_hit_x -= floor(wall_draw->wall_hit_x);
    
    // Calculate step size for texture mapping
    wall_draw->texture_step = 1.0 * texture->img_height / wall_draw->line_length;
    
    // Initial texture position
    wall_draw->texture_position = (wall_draw->start_draw - WINDOW_SIZE_Y / 2 + wall_draw->line_length / 2) * wall_draw->texture_step;
}

// Draw a vertical slice of the wall on the screen
void render_wall_slice(t_game *game, t_ray_calc *ray_calc, t_texture *texture) {
    t_wall_draw wall_draw;
    int y;
    int color;
    int texture_y;

    select_texture(game, ray_calc, texture);
    calculate_wall_dimensions(game, ray_calc, &wall_draw, texture);

    // Calculate x-coordinate for texture
    texture->texture_x = (int)(wall_draw.wall_hit_x * (float)texture->img_width);
    
    // Adjust texture x-coordinate based on wall side
    if (ray_calc->hit_side == 0 && ray_calc->ray_dir.x_coord > 0)
        texture->texture_x = texture->img_width - texture->texture_x - 1;
    if (ray_calc->hit_side == 1 && ray_calc->ray_dir.y_coord < 0)
        texture->texture_x = texture->img_width - texture->texture_x - 1;

    // Render each pixel of the wall slice
    y = wall_draw.start_draw;
    while (y < wall_draw.end_draw) {
        texture_y = (int)wall_draw.texture_position & (texture->img_height - 1);
        color = get_image_pixel(texture, texture->texture_x, texture_y);
        draw_pixel(&game->texture_data, ray_calc->screen_x, y, color);
        wall_draw.texture_position += wall_draw.texture_step;
        y++;
    }
}

// Select the correct texture based on the wall side and ray direction
void select_texture(t_game *game, t_ray_calc *ray_calc, t_texture *texture) {
    if (ray_calc->hit_side == 0) { // Check if the wall is hit vertically
        if (ray_calc->ray_dir.x_coord > 0)
            *texture = game->textures[EAST]; // Use east texture
        else
            *texture = game->textures[WEST]; // Use west texture
    } else { // The wall is hit horizontally
        if (ray_calc->ray_dir.y_coord > 0)
            *texture = game->textures[SOUTH]; // Use south texture
        else
            *texture = game->textures[NORTH]; // Use north texture
    }
}
