#include "cub3d.h"

// Set a pixel in the image data
void draw_pixel(t_texture *image_data, int x, int y, int color) {
    char *dst;

    dst = image_data->address + (y * image_data->size_line + x * (image_data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// Draw the ceiling of the scene
void draw_ceiling(t_game *game, int color) {
    int y, x;

    for (y = 0; y < WINDOW_SIZE_Y / 2; y++) {
        for (x = 0; x < WINDOW_SIZE_X; x++)
            draw_pixel(&game->texture_data, x, y, color);
    }
    mlx_put_image_to_window(game->mlx_instance, game->window, game->texture_data.img, 0, 0);
}

// Draw the floor of the scene
void draw_floor(t_game *game, int color) {
    int y, x;

    for (y = WINDOW_SIZE_Y / 2; y < WINDOW_SIZE_Y; y++) {
        for (x = 0; x < WINDOW_SIZE_X; x++)
            draw_pixel(&game->texture_data, x, y, color);
    }
    mlx_put_image_to_window(game->mlx_instance, game->window, game->texture_data.img, 0, 0);
}

// Clear the image to black
void clear_image(t_game *game) {
    int y, x;

    for (y = 0; y < WINDOW_SIZE_Y; y++) {
        for (x = 0; x < WINDOW_SIZE_X; x++)
            draw_pixel(&game->texture_data, x, y, 0x000000);
    }
    mlx_put_image_to_window(game->mlx_instance, game->window, game->texture_data.img, 0, 0);
}

// Retrieve a pixel from the texture
int get_image_pixel(t_texture *texture, int x, int y) {
    unsigned int color;
    char *dst;

    if (y <= 0) {
        y = 0;
    }
    dst = texture->address + (y * texture->size_line + (x * (texture->bits_per_pixel / 8)));
    color = *(unsigned int *)dst;
    return color;
}
