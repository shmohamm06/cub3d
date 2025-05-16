/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:18:00 by shmohamm          #+#    #+#             */
/*   Updated: 2025/05/16 16:06:07 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define PI 3.1415926535

// structs
enum
{
	NO_MOVE = 0,
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4,
	FLOOR = 5,
	CEILING = 6,
};

typedef struct s_input
{
	_Bool		up;
	_Bool		down;
	_Bool		left;
	_Bool		right;
	_Bool		turn_left;
	_Bool		turn_right;
}				t_input;

typedef struct s_vector
{
	float		x_coord;
	float		y_coord;
}				t_vector;

typedef struct s_gamer
{
	t_vector	position;
	t_vector	velocity;
	t_vector	direction;
	t_vector	view_plane;
	float		rotation_angle;
}				t_gamer;

typedef struct s_texture
{
	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			img_width;
	int			img_height;
	int			texture_y;
	int			texture_x;
	char		**texture_map;
}				t_texture;

typedef struct s_ray_calc
{
	int			screen_x;
	float		camera_plane_x;
	t_vector	ray_dir;
	t_vector	side_distance;
	t_vector	delta_distance;
	t_vector	step_direction;
	t_vector	grid_pos;
	int			hit_side;
	float		wall_dist;
}				t_ray_calc;

typedef struct s_wall_draw
{
	int			line_length;
	int			start_draw;
	int			end_draw;
	float		wall_hit_x;
	float		texture_step;
	float		texture_position;
}				t_wall_draw;

typedef struct s_tex_paths
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_tex_paths;

typedef struct s_map
{
	int			x;
	int			y;
	char		**blocks;
	int			block_size;
}				t_map;

typedef struct s_game
{
	int			floor_color;
	int			ceiling_col;
	t_texture	texture_data;
	void		*mlx;
	void		*window;
	char		**map_data;
	bool		display_map;
	char		player_initial_pos;
	t_gamer		player;
	t_map		map;
	t_input		input;
	t_tex_paths	texture_paths;
	t_texture	textures[5];
}				t_game;

# define ESC 53
# define UP 126
# define DOWN 125
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define RIGHT 124
# define LEFT 123
# define SHOW_MAP 46
# define ON_MOUSE_DW 4

// cub3d
void			setup_hooks(t_game *game);

// check_files
bool			check_file_type(char *str);
bool			check_all_textures(t_game *cub3d);
int				valid_file_path(char *path);
int				map_empty(t_game *cub3d);
int				open_map(char *av);

// check_map
int				check_contents(t_game *cub3d);
int				check_map(t_game *cub3d);
int				check_map_validity(t_game *cub3d, int y, int x);
int				check_inside_map(t_game *cub3d);

// check_map 2
int				player_direction(t_game *cub3d, int size_x, int size_y,
					int player_pos);
int				check_top_and_bottom(t_game *cub3d);
int				check_horizontal(t_game *cub3d);
int				check_vertical(t_game *cub3d);
int				check_maps_sides(t_game *cub3d);

// draw_wall
void			calculate_wall_dimensions(t_game *game, t_ray_calc *ray_calc,
					t_wall_draw *wall_draw, t_texture *texture);
void			render_wall_slice(t_game *game, t_ray_calc *ray_calc,
					t_texture *texture);

// init
void			begin_execution(t_game *cub3d);
int				render_scene(t_game *cub3d);
void			init_data(t_game *cub3d);
void			keys(t_game *cub3d);
void			create_image(t_game *cub3d);

// key_moves
void			move_player_forward(t_game *game);
void			move_player_backward(t_game *game);
void			strafe_player_right(t_game *game);
void			strafe_player_left(t_game *game);

// key_rotation
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);

// key
void			release_textures(t_game *game, t_texture *textures);
int				terminate_game(t_game *game);
int				update_movement(t_game *game);
int				handle_key_press(int keycode, t_game *game);
int				handle_key_release(int keycode, t_game *game);

// map utils
int				save_texture_path(char **str, char **texture);
int				ignore_header(int fd);
int				fill_line(char **line, int size, char c);
int				fill_map(int fd, t_game *cub3d, int size_x, int i);
int				assign_map_coords(int fd, int *x, int *y);

// map
int				read_map(char *map, int *x, int *y);
int				map(char *map, t_game *cub3d);

// parse map
int				parse_map(int fd, t_game *cub3d, int size_x, int size_y);
int				parse_map_header(t_game *cub3d, char **spl, bool *floor,
					bool *ceiling);
int				parse_header(int fd, t_game *cub3d, int flag);

// ray_calculation
t_vector		calculate_ray_direction(t_game *cub3d, float camera_x);
t_vector		calculate_delta_distance(t_vector *ray_direction);
t_vector		calculate_step(t_vector *ray_direction);
t_vector		calcsid(t_game *cub3d, t_vector *rayd, t_vector *map,
					t_vector *deltd);

// raycast_help
void			perform_dda(t_game *cub3d, t_ray_calc *rc);
void			init_calc(t_game *cub3d, int x, t_ray_calc *rc);
void			pick_texture(t_game *cub3d, t_ray_calc *ray_calc,
					t_texture *texture);
void			calculate_distance_to_wall(t_ray_calc *ray_calc);
// raycast
void			cast_one_ray(t_game *cub3d, int x, t_texture *texture);
void			raycast(t_game *cub3d, t_texture *texture);

// textures
void			init_tex(t_game *cub3d);
void			init_tex_values(t_texture *texture);
void			fill_walls(t_game *cub3d, t_texture *tex, char *path);
void			check_and_load_textures(t_game *cub3d);
bool			check_texture_conversion(t_game *cub3d);

// utils_draw
void			my_mlx_pixel_put(t_texture *image_data, int x, int y,
					int color);
void			draw_ceiling(t_game *game, int color);
void			draw_floor(t_game *game, int color);
void			clear_image(t_game *game);
int				get_image_pixel(t_texture *texture, int x, int y);

// utils
float			to_radians(float n);
int				args_check(int ac);
char			**remove_nl(char *line);
int				free_2d(char **s);
int				free_texture_paths(t_game *cub3d);

// utils_2
void			check_and_exit(int condition, const char *message,
					int exit_code);
int				parse_colour(char *colour, int *hex_colour);
void			check_plane(t_game *cub3d);
void			check_files_accessibility(void);
void			check_player_direction(t_game *cub3d);

#endif