/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:18:00 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/27 17:46:10 by shmohamm         ###   ########.fr       */
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

# define WINDOW_SIZE_X 800
# define WINDOW_SIZE_Y 800
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
	void		*mlx_instance;
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

// utils
int				args_check(int ac);
float			to_radians(float n);
char			**remove_nl(char *line);
int				free_2d(char **s);
int				free_texture_paths(t_game *cub3d);

// utils_2
void			check_and_exit(int condition, const char *message,
					int exit_code);

// init
void			init_data(t_game *cub3d);

// map
int				read_map(char *map, int *x, int *y);
int				map(char *map, t_game *cub3d);

// parse map
int				parse_map(int fd, t_game *cub3d, int size_x, int size_y);
int				parse_map_header(t_game *cub3d, char **spl, bool *floor,
					bool *ceiling);
int				parse_header(int fd, t_game *cub3d, int flag);

// check_map
int				map_empty(t_game *cub3d);
int				check_contents(t_game *cub3d);
int				check_map(t_game *cub3d);

// check_map 2
int				player_direction(t_game *cub3d, int size_x, int size_y,
					int player_pos);
int				check_top_and_bottom(t_game *cub3d);
int				check_horizontal(t_game *cub3d);
int				check_vertical(t_game *cub3d);
int				check_maps_sides(t_game *cub3d);

// check_map 3
int				check_map_validity(t_game *cub3d, int y, int x);
int				check_inside_map(t_game *cub3d);
int				open_map(char *av);

// check_files
int				load_texture(char **str, char **texture);
bool			check_file_type(char *str);
bool			check_all_textures(t_game *cub3d);

// map utils
int				valid_file_path(char *path);
int				ignore_header(int fd);
int				fill_line(char **line, int size, char c);
int				fill_map(int fd, t_game *cub3d, int size_x, int i);
int				assign_map_coords(int fd, int *x, int *y);

// colours
int				parse_colour(char *colour, int *hex_colour);

#endif