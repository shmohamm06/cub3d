/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:18:00 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/22 19:40:30 by shmohamm         ###   ########.fr       */
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

/*---------structs---------*/
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
	void		*texture_img;
	char		*texture_addr;
	int			bpp;
	int			line_size;
	int			byte_order;
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
	int			ceiling_color;
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
/*---------structs---------*/

int				args_check(int ac);
float			to_radians(float n);
void			init_data(t_game *cub3d);
int				assign_map_coords(int fd, int *x, int *y);
int				check_empty(t_game *cub3d);
int				check_validity(t_game *cub3d);
int				free_2d(char **s);
int				open_map(char *av);

#endif