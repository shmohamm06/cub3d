#include "cub3d.h"

// Convert degrees to radians
float to_radians(float degrees) {
    return degrees * (PI / 180.0f);
}

// Move the player forward
void move_player_forward(t_game *game) {
    t_vector new_pos;
    new_pos.x_coord = game->player.position.x_coord + game->player.direction.x_coord * 0.1f;
    new_pos.y_coord = game->player.position.y_coord + game->player.direction.y_coord * 0.1f;

    // Check for collisions in the x-direction
    if (game->map.blocks[(int)game->player.position.y_coord][(int)new_pos.x_coord] != '1')
        game->player.position.x_coord = new_pos.x_coord;

    // Check for collisions in the y-direction
    if (game->map.blocks[(int)new_pos.y_coord][(int)game->player.position.x_coord] != '1')
        game->player.position.y_coord = new_pos.y_coord;
}

// Move the player backward
void move_player_backward(t_game *game) {
    t_vector new_pos;
    new_pos.x_coord = game->player.position.x_coord - game->player.direction.x_coord * 0.1f;
    new_pos.y_coord = game->player.position.y_coord - game->player.direction.y_coord * 0.1f;

    // Check for collisions in the x-direction
    if (game->map.blocks[(int)game->player.position.y_coord][(int)new_pos.x_coord] != '1')
        game->player.position.x_coord = new_pos.x_coord;

    // Check for collisions in the y-direction
    if (game->map.blocks[(int)new_pos.y_coord][(int)game->player.position.x_coord] != '1')
        game->player.position.y_coord = new_pos.y_coord;
}

// Strafe player to the right
void strafe_player_right(t_game *game) {
    t_vector new_pos, strafe_dir;
    float angle = to_radians(90);

    // Calculate strafe direction
    strafe_dir.x_coord = game->player.direction.x_coord * cos(angle) - game->player.direction.y_coord * sin(angle);
    strafe_dir.y_coord = game->player.direction.x_coord * sin(angle) + game->player.direction.y_coord * cos(angle);

    new_pos.x_coord = game->player.position.x_coord + strafe_dir.x_coord * 0.1f;
    new_pos.y_coord = game->player.position.y_coord + strafe_dir.y_coord * 0.1f;

    // Check for collisions in the x-direction
    if (game->map.blocks[(int)game->player.position.y_coord][(int)new_pos.x_coord] != '1')
        game->player.position.x_coord = new_pos.x_coord;

    // Check for collisions in the y-direction
    if (game->map.blocks[(int)new_pos.y_coord][(int)game->player.position.x_coord] != '1')
        game->player.position.y_coord = new_pos.y_coord;
}

// Strafe player to the left
void strafe_player_left(t_game *game) {
    t_vector new_pos, strafe_dir;
    float angle = to_radians(-90);

    // Calculate strafe direction
    strafe_dir.x_coord = game->player.direction.x_coord * cos(angle) - game->player.direction.y_coord * sin(angle);
    strafe_dir.y_coord = game->player.direction.x_coord * sin(angle) + game->player.direction.y_coord * cos(angle);

    new_pos.x_coord = game->player.position.x_coord + strafe_dir.x_coord * 0.1f;
    new_pos.y_coord = game->player.position.y_coord + strafe_dir.y_coord * 0.1f;

    // Check for collisions in the x-direction
    if (game->map.blocks[(int)game->player.position.y_coord][(int)new_pos.x_coord] != '1')
        game->player.position.x_coord = new_pos.x_coord;

    // Check for collisions in the y-direction
    if (game->map.blocks[(int)new_pos.y_coord][(int)game->player.position.x_coord] != '1')
        game->player.position.y_coord = new_pos.y_coord;
}
