/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:05:10 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/22 17:59:52 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void initializaion(t_info *info)
{
	t_vars	vars;
	t_player player;
	t_map map;
	
	init_window(&vars);
	init_image(&vars,info,&map);
	init_plane(info,&map);
	init_player(&player,info);
	process_ray_casting(&player,&map,&vars);
	mlx_loop(vars.mlx);
}

void init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if(!vars->mlx)
		put_error_message("mlx_init");
	vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT,"cub3D");
	if(!vars->win)
		put_error_message("mlx_new_window");
	vars->img.img = mlx_new_image(vars->mlx, W_WIDTH, W_HEIGHT);
	if(!vars->img.img)
		put_error_message("mlx_new_image");
	vars->img.addr = mlx_get_data_addr(vars->img.img,&vars->img.bits_per_pixel,&vars->img.line_length,&vars->img.endian);
	if(!vars->img.addr)
		put_error_message("mlx_get_data_addr");
}

void init_image(t_vars *vars,t_info *info,t_map *map)
{
	map->image[0].img = mlx_xpm_file_to_image(vars->mlx,info->north,&(map->image[0].width),&(map->image[0].height));
	map->image[1].img = mlx_xpm_file_to_image(vars->mlx,info->west,&(map->image[1].width),&(map->image[1].height));
	map->image[2].img = mlx_xpm_file_to_image(vars->mlx,info->south,&(map->image[2].width),&(map->image[2].height));
	map->image[3].img = mlx_xpm_file_to_image(vars->mlx,info->east,&(map->image[3].width),&(map->image[3].height));
	if(!map->image[0].img || !map->image[1].img || !map->image[2].img || !map->image[3].img)
		put_error_message("mlx_xpm_file_to_image");
	map->image[0].addr = mlx_get_data_addr(map->image[0].img,&(map->image[0].bits_per_pixel),&(map->image[0].line_length),&(map->image[0].endian));
	map->image[1].addr = mlx_get_data_addr(map->image[1].img,&(map->image[1].bits_per_pixel),&(map->image[1].line_length),&(map->image[1].endian));
	map->image[2].addr = mlx_get_data_addr(map->image[2].img,&(map->image[2].bits_per_pixel),&(map->image[2].line_length),&(map->image[2].endian));
	map->image[3].addr = mlx_get_data_addr(map->image[3].img,&(map->image[3].bits_per_pixel),&(map->image[3].line_length),&(map->image[3].endian));
	if(!map->image[0].addr || !map->image[1].addr || !map->image[2].addr || !map->image[3].addr)
		put_error_message("mlx_get_data_addr");
}