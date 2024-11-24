/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:40:05 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/23 00:15:40 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub_3d.h"

// void process_ray_casting(t_player *player, t_map *map,t_vars *vars)
// {
// 	int	i;
// 	int	j;
// 	t_vector intersection;
// 	t_plane *opt;
// 	t_vector ray;

// 	i = 0;
// 	while(i < W_HEIGHT)
// 	{
// 		j = 0;
// 		while(j < W_WIDTH)
// 		{
// 			ray = get_ray_for_pixel(player,i,j);
// 			do
// 			{
// 				opt = search_opt_obj(player,map);
// 			} while ((!(opt && ray_to_plane(player,opt,&intersection,ray))) && check_all_searched(map->plane));
// 			// printf("opt index = %d, pos.x = %f\n",opt->index,opt->point.x);
// 			if(check_all_searched(map->plane))
// 				set_pixel(get_pixel(map,intersection,opt),&vars->img.addr[i*vars->img.line_length + j*(vars->img.bits_per_pixel / 8)]);
// 			else
// 			printf("i = %d, j = %d\n",i,j);
// 			bzero_searched(map->plane);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if(!mlx_put_image_to_window(vars->mlx,vars->win,vars->img.img,0,0))
// 		put_error_message("mlx_put_image_to_window");
// }

// t_vector get_ray_for_pixel(t_player *player, int i, int j)
// {
// 	t_vector screen;
// 	t_vector ray;
// 	float	fov;
	
// 	fov = 90.0f;
// 	fov = fov * (M_PI / 180.0f);
// 	screen.x = (2 * ((j + 0.5f) / W_WIDTH) - 1) * tan(fov / 2.0f) * (W_WIDTH/ W_HEIGHT);
// 	screen.y = (1 - 2 * ((i + 0.5f) / W_HEIGHT)) * tan(fov / 2.0f);
// 	screen.z = 1;
// 	player->ray_screen[i][j] = screen;
// 	ray.x = screen.x * player->right.x + screen.y *player->up.x + screen.z * player->front.x;
// 	ray.y = screen.x * player->right.y + screen.y *player->up.y + screen.z * player->front.y;
// 	ray.z = screen.x * player->right.z + screen.y *player->up.z + screen.z * player->front.z;
// 	// printf("x = %f, ",ray.x);
// 	// printf("y = %f, ",ray.y);
// 	// printf("z = %f\n",ray.z);
// 	return (normarize(ray));
// }

// t_plane *search_opt_obj(t_player *player, t_map *map)
// {
// 	t_plane *tmp;
// 	t_plane *near;

// 	tmp = map->plane;
// 	near = tmp;
// 	while(tmp)
// 	{
// 		if((distance(player->pos,tmp->point) < distance(player->pos,near->point) || near->searched == 1) && tmp->searched == 0)
// 		{
// 			// printf("tmp index = %d\n",tmp->index);
// 			near = tmp;
// 		}
// 		tmp = tmp->next;
// 	}
// 	near->searched = 1;
// 	// printf("near pos.x = %f, ",near->point.x);
// 	// printf("near pos.y = %f,\n",near->point.y);
// 	// printf("near index = %d\n",near->index);
// 	return (near);
// }

// int ray_to_plane(t_player *player,t_plane *plane,t_vector *pos,t_vector ray)
// {
// 	t_vector	scalar;
// 	float		t;
	
// 	t = dot(difference(player->pos,plane->point),plane->normal) / dot(ray,plane->normal);
// 	scalar.x = t*ray.x;
// 	scalar.y = t*ray.y;
// 	scalar.z = t*ray.z;
// 	*pos = sum(player->pos,scalar);
// 	// *pos = difference(scalar,player->pos);
// 	// printf("o_x = %f, ",pos->x);
// 	// printf("o_y = %f, ",pos->y);
// 	// printf("o_z = %f\n",pos->z);
// 	// printf("p_x = %f, ",player->pos.x);
// 	// printf("p_y = %f, ",player->pos.y);
// 	// printf("p_z = %f\n",player->pos.z);
// 	if(plane->type == 1 || plane->type == 3)
// 	{
// 		if((pos->x >= plane->point.x - 32 && pos->x <= plane->point.x + 32) && pos->z >=0 && pos->z <=64)
// 			return (1);
// 	}
// 	else if(plane->type == 2 || plane->type == 4)
// 	{
// 		if(pos->y >= plane->point.y - 32 && pos->y <= plane->point.y + 32 && pos->z >=0 && pos->z <=64)
// 			return (1);
// 	}
// 	return (0);
// }

// char* get_pixel(t_map *map,t_vector pos,t_plane *plane)
// {
// 	int x;
// 	int y;

// 	if(plane->type == 1 || plane->type == 3)
// 	{
// 		x = pos.x - plane->point.x + 32;
// 		y = 64 - pos.z;
// 		printf("x = %d, y = %d\n",x,y);
// 		return (&map->image[plane->type -1].addr[y*map->image[plane->type-1].line_length + x*(map->image[plane->type-1].bits_per_pixel / 8)]);
// 	}
// 	else if(plane->type == 2 || plane->type == 4)
// 	{
// 		x = pos.y - plane->point.y + 32;
// 		y = 64 -pos.z;
// 		printf("x = %d, y = %d\n",x,y);
// 		return (&map->image[plane->type -1].addr[y*map->image[plane->type-1].line_length + x*(map->image[plane->type-1].bits_per_pixel / 8)]);
// 	}
// 	return (0);
// }

// void set_pixel(char *src,char *dst)
// {
// 	dst[0] = src[0];
// 	dst[1] = src[1];
// 	dst[2] = src[2];
// 	// dst[3] = src[3];
// }

// void bzero_searched(t_plane *first)
// {
// 	t_plane *tmp;

// 	tmp = first;
// 	while(tmp)
// 	{
// 		tmp->searched = 0;
// 		tmp = tmp->next;
// 	}
// }

// int check_all_searched(t_plane *first)
// {
// 	t_plane *tmp;

// 	tmp = first;
// 	while(tmp)
// 	{
// 		if(tmp->searched == 0)
// 		{
// 			return (1);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }