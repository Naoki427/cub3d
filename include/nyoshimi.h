/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyoshimi.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:48:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/25 17:59:07 by nyoshimi         ###   ########.fr       */
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
#define ROT_LEFT 1
#define ROT_RIGHT 1
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define MOV_SPEED 0.01
#define ROT_SPEED 1
# define KEY_PRESS 2
# define KEY_RELEASE 3

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
	double	z;
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
	// t_plane	*plane;
	t_color		floor;
	t_color		ceiling;
	// int		*searched_flg;
	t_data	image[4];
	// int		box_num;
}t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	front;
	t_vector	up;
	t_vector	right;
	int			move_flg;
	int			turn_flg;
	t_map		*map;
	// t_vector	ray_screen[W_HEIGHT][W_WIDTH];
} t_player;

typedef struct s_tool
{
	double fovX;
	double fovY;
	double rayX;
	double rayY;
	double cameraX;
	double toNearX;
	double toNearY;
	double toNextX;
	double toNextY;
	int focusX;
	int focusY;
	double time;
	double oldTime;
	int is_hit;
	int side;
	double stepX;
	double stepY;
	double verDistance;
	int lineHeight;
	int pixStart;
	int pixEnd;
	double wallX;
	int imgX;
	int imgY;
	t_color color;
	t_player *player;
	t_map *map;
	t_vars *vars;
} t_tool;

// typedef struct s_plane
// {
// 	int	type;
// 	int	index;
// 	t_vector normal;
// 	t_vector point;
// 	void *next;
// 	int searched;
// } t_plane;



//initialization.c
void initializaion(t_info *info);
void init_window(t_vars *vars);
void init_image(t_vars *vars,t_info *info,t_map *map);
void init_tool(t_tool *tool,t_player *player,t_vars *vars,t_map *map);

//player.c
void init_player(t_player *player, t_info *init_info,t_map *map);
void init_posision(t_player *player, t_info *init_info,int i,int j);
void get_right_and_up_vector(t_player *player);

//vecor.c
t_vector normarize(t_vector v);
t_vector cross(t_vector a,t_vector b);
float distance(t_vector a, t_vector b);
float dot(t_vector a, t_vector b);
t_vector sum(t_vector o, t_vector p);
t_vector difference(t_vector o, t_vector p);
t_vector product(t_vector o, t_vector p);

//error.c
void put_error_message(char *message);

//plane.c
// void init_plane(t_info *init_info,t_map *map);
// t_plane *lstnew_plane(int i,int j,int index);
// void lstadd_back_plane(t_plane *first,t_plane *new);
// void complete_four_edge(int i,int j,t_plane *first,int index);
// void init_plane_param(int i, int j,int type, t_plane *plane);
// void init_searched_flg(t_map *map);
// void bzero_searched_flg(t_map *map);

//ray.c
// void process_ray_casting(t_player *player, t_map *map,t_vars *vars);
// t_vector get_ray_for_pixel(t_player *player, int i, int j);
// t_plane *search_opt_obj(t_player *player, t_map *map);
// int ray_to_plane(t_player *player,t_plane *plane,t_vector *pos,t_vector ray);
// char* get_pixel(t_map *map,t_vector pos,t_plane *plane);
// void set_pixel(char *src,char *dst);
// void bzero_searched(t_plane *first);
// int check_all_searched(t_plane *first);

//raycast.c
void do_ray_cast(t_tool *tool);

int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
int loop_hook(t_tool *tool);

#endif