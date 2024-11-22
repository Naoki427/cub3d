/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:14:40 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/22 17:01:04 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void init_plane(t_info *init_info,t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->box_num = 0;
	while(init_info->map[i])
	{
		j = 0;
		while (init_info->map[i][j])
		{
			if(init_info->map[i][j] == '1')
			{
				if(map->box_num == 0)
					map->plane = lstnew_plane(i,j,0);
				else
					lstadd_back_plane(map->plane,lstnew_plane(i,j,4*map->box_num));
				complete_four_edge(i,j,map->plane,4*map->box_num);
				map->box_num++;
			}
			j++;
		}
		i++;
	}
	init_searched_flg(map);
}

t_plane *lstnew_plane(int i,int j,int index)
{
	t_plane *new;

	new = (t_plane *)malloc(sizeof(t_plane));
	if(!new)
		put_error_message("malloc");
	new->index = index;
	init_plane_param(i,j,1,new);
	new->next = NULL;
	new->searched = 0;
	new->type = 1;
	return (new);
}

void lstadd_back_plane(t_plane *first,t_plane *new)
{
	t_plane *tmp;
	
	tmp = first;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void complete_four_edge(int i,int j,t_plane *first,int index)
{
	t_plane *left;
	t_plane *bottom;
	t_plane *right;

	left = (t_plane *)malloc(sizeof(t_plane));
	bottom = (t_plane *)malloc(sizeof(t_plane));
	right = (t_plane *)malloc(sizeof(t_plane));
	if(!left || !bottom || !right)
		put_error_message("malloc");
	left->index = index + 1;
	bottom->index = index + 2;
	right->index = index + 3;
	left->searched = 0;
	bottom->searched = 0;
	right->searched = 0;
	left->type = 2;
	bottom->type = 3;
	right->type = 4;
	init_plane_param(i,j,2,left);
	init_plane_param(i,j,3,bottom);
	init_plane_param(i,j,4,right);
	lstadd_back_plane(first,left);
	left->next = bottom;
	bottom->next = right;
	right->next = NULL;
}

void init_plane_param(int i, int j,int type, t_plane *plane)
{
	plane->normal.x = 0.0f;
	plane->normal.y = 0.0f;
	plane->normal.z = 0.0f;
	plane->point.z = 32;
	if(type == 1)
	{
		plane->normal.y = -1.0f;
		plane->point.x = j*64 + 32;
		plane->point.y = i*64;
	}
	if(type == 2)
	{
		plane->normal.x = -1.0f;
		plane->point.x = j*64;
		plane->point.y = i*64 + 32;
	}
	if(type == 3)
	{
		plane->normal.y = 1.0f;
		plane->point.x = j*64 + 32;
		plane->point.y = i*64 + 63;
	}
	if(type == 4)
	{
		plane->normal.x = 1.0f;
		plane->point.x = j*64 + 63;
		plane->point.y = i*64 + 32;
	}
}

void init_searched_flg(t_map *map)
{
	map->searched_flg = (int *)malloc(sizeof(int)*map->box_num);
	if(!map->searched_flg)
		put_error_message("malloc");
	bzero_searched_flg(map);
}

void bzero_searched_flg(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->box_num)
	{
		map->searched_flg[i] = 0;
		i++;
	}
}