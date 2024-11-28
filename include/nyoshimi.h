/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyoshimi.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:48:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/28 20:34:14 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NYOSHIMI_H
#define NYOSHIMI_H
#include "mlx.h"
#include "mlx_int.h"
#include "math.h"

#define W_WIDTH 1440
#define W_HEIGHT 1080

#define UP 1
#define DOWN  2
#define LEFT  3
#define RIGHT 4
#define ROT_LEFT 5
#define ROT_RIGHT 6
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define ON_DESTROY 65307
#define MOV_SPEED 0.2
#define ROT_SPEED 1
# define KEY_PRESS 2
# define KEY_RELEASE 3
#define PI 3.14159265358979323846 

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;

	t_data		img;
}				t_vars;

typedef struct s_vecror
{
	double	x;
	double	y;
	// double	z;
} t_vector;

typedef struct s_color
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;
} t_color;



typedef struct s_map
{
	char 	**map;
	t_color		floor;
	t_color		ceiling;
	t_data	image[4];
}t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	front;
	t_vector	right;
	int			move_flg;
	int			turn_flg;
	t_map		*map;
} t_player;

typedef struct s_tool
{
	double fov_x;
	double fov_y;
	double ray_x;
	double ray_y;
	double camera_x;
	double to_near_x;
	double to_near_y;
	double to_next_x;
	double to_next_y;
	int focus_x;
	int focus_y;
	double time;
	double old_time;
	int is_hit;
	int side;
	double step_x;
	double step_y;
	double ver_distance;
	int line_height;
	int pix_start;
	int pix_end;
	int pix_top;
	double wall_x;
	int img_x;
	int img_y;
	t_color color;
	t_player *player;
	t_map *map;
	t_vars *vars;
} t_tool;

//main.c
void do_ray_cast(t_tool *tool);

//start.c
void	start_ray_cast(t_info *info);
void init_window(t_vars *vars);
void suceed_map(t_info *info, t_map *map);
void init_image(t_vars *vars,t_info *info,t_map *map);
void init_tool(t_tool *tool,t_player *player,t_vars *vars,t_map *map);

//player.c
void init_player(t_player *player, t_info *init_info,t_map *map);
void init_posision(t_player *player, t_info *init_info,int i,int j);

//vecor.c
t_vector reverse(t_vector vec);
t_vector rotate(t_vector vec, double rad);

//n_utils.c
void put_error_message(char *message);
int close_window(t_tool *tool);

//raycast.c
void	set_ray_var(t_tool *tool, int x);
void	set_step_var(t_tool *tool);
void	shoot_ray(t_tool *tool);
void	set_distance(t_tool *tool);
void	set_pixel(t_tool *tool, int x);

//hook.c
int key_press(int keycode, t_tool *tool);
int loop_hook(t_tool *tool);

//color.c
t_color get_color(char *addr);
void set_color(char *addr,t_color color);

#endif