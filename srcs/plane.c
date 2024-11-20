/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:14:40 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/20 18:16:37 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void init_plane(t_info *init_info,t_map *map)
{
	int	i;
	int	j;
	int	box_num;

	i = 0;
	box_num = 0;
	while(init_info->map[i])
	{
		j = 0;
		while (init_info->map[i][j])
		{
			if(init_info->map[i][j] == "1")
			{
				if(box_num == 0)
					map->plane = lstnew_plane(i,j,0);
				else
					lstadd_back_plane(map->plane,lstnew_plane(i,j,4*box_num));
				complete_four_edge(i,j,map->plane,4*box_num);
				box_num++;
			}
			j++;
		}
		i++;
	}
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
	plane->normal.x = 0;
	plane->normal.y = 0;
	plane->normal.z = 0;
	plane->point.z = 32;
	if(type == 1)
	{
		plane->normal.y = 1;
		plane->point.x = j*64 + 32;
		plane->point.y = i*64;
	}
	if(type == 2)
	{
		plane->normal.x = 1;
		plane->point.x = j*64;
		plane->point.y = i*64 + 32;
	}
	if(type == 3)
	{
		plane->normal.y = -1;
		plane->point.x = j*64 + 32;
		plane->point.y = i*64 + 63;
	}
	if(type == 4)
	{
		plane->normal.x = -1;
		plane->point.x = j*64 + 63;
		plane->point.y = i*64 + 32;
	}
}
