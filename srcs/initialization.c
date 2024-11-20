/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:05:10 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/20 18:15:35 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void initializaion(t_info *init_info)
{
	t_vars	vars;
	
	init_window(&vars);
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
}




