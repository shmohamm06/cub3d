#include "cub3d.h"

// Rotate player view to the left
void rotate_left(t_game *game) {
    t_vector new_view_plane, new_direction;
    float rotation_speed = -0.03f;

    // Calculate new direction vector
    new_direction.x_coord = game->player.direction.x_coord * cos(rotation_speed) - game->player.direction.y_coord * sin(rotation_speed);
    new_direction.y_coord = game->player.direction.x_coord * sin(rotation_speed) + game->player.direction.y_coord * cos(rotation_speed);

    // Calculate new view plane vector
    new_view_plane.x_coord = game->player.view_plane.x_coord * cos(rotation_speed) - game->player.view_plane.y_coord * sin(rotation_speed);
    new_view_plane.y_coord = game->player.view_plane.x_coord * sin(rotation_speed) + game->player.view_plane.y_coord * cos(rotation_speed);

    // Update player's direction and view plane
    game->player.direction = new_direction;
    game->player.view_plane = new_view_plane;
}

// Rotate player view to the right
void rotate_right(t_game *game) {
    t_vector new_view_plane, new_direction;
    float rotation_speed = 0.03f;

    // Calculate new direction vector
    new_direction.x_coord = game->player.direction.x_coord * cos(rotation_speed) - game->player.direction.y_coord * sin(rotation_speed);
    new_direction.y_coord = game->player.direction.x_coord * sin(rotation_speed) + game->player.direction.y_coord * cos(rotation_speed);

    // Calculate new view plane vector
    new_view_plane.x_coord = game->player.view_plane.x_coord * cos(rotation_speed) - game->player.view_plane.y_coord * sin(rotation_speed);
    new_view_plane.y_coord = game->player.view_plane.x_coord * sin(rotation_speed) + game->player.view_plane.y_coord * cos(rotation_speed);

    // Update player's direction and view plane
    game->player.direction = new_direction;
    game->player.view_plane = new_view_plane;
}
