/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyoshimi.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:48:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/20 18:17:34 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NYOSHIMI_H
#define NYOSHIMI_H
#include "mlx.h"

#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;

	t_data		img;
}				t_vars;

typedef struct s_vecror
{
	float	x;
	float	y;
	float	z;
} t_vector;

typedef struct s_tool
{
	int	img_width[4];
	int	img_height[4];
}				t_tool;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	int			move_flg;
	int			turn_flg;
} t_player;

typedef struct s_map
{
	t_plane	*plane;
	int		*searched_flg;
}t_map;

typedef struct s_plane
{
	int	type;
	int	index;
	t_vector normal;
	t_vector point;
	void *next;
} t_plane;

//initialization.c
void initializaion(t_info *init_info);
void init_window(t_vars *vars);

//error.c
void put_error_message(char *message);

//plane.c
void init_plane(t_info *init_info,t_map *map);
t_plane *lstnew_plane(int i,int j,int index);
void lstadd_back_plane(t_plane *first,t_plane *new);
void complete_four_edge(int i,int j,t_plane *first,int index);
void init_plane_param(int i, int j,int type, t_plane *plane);
#endif