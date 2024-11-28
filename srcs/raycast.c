/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:53:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/26 18:57:14 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void do_ray_cast(t_tool *tool)
{
	int x = 0;
	while(x < W_WIDTH)
	{
		tool->camera_x = 2*x/ (double)W_WIDTH -1;
		tool->ray_x = tool->player->front.x + tool->fov_x*tool->camera_x;
		tool->ray_y = tool->player->front.y + tool->fov_y*tool->camera_x;
		tool->focus_x = tool->player->pos.x;
		tool->focus_y = tool->player->pos.y;
		if(tool->ray_x == 0)
			tool->to_next_x = __INT_MAX__;
		else if(tool->ray_x > 0)
			tool->to_next_x = 1/tool->ray_x;
		else
			tool->to_next_x = -1/tool->ray_x;
		if(tool->ray_y == 0)
			tool->to_next_y = __INT_MAX__;
		else if(tool->ray_y > 0)
			tool->to_next_y= 1/tool->ray_y;
		else
			tool->to_next_y = -1/tool->ray_y;
		if(tool->ray_x < 0)
		{
			//up
			//just distance not vector
			tool->step_x = -1;
			tool->to_near_x = (tool->player->pos.x - tool->focus_x)*tool->to_next_x;
		}
		else
		{
			//down
			tool->step_x = 1;
			tool->to_near_x = (tool->focus_x + 1.0 -tool->player->pos.x)*tool->to_next_x;
		}
		if(tool->ray_y < 0)
		{
			//up
			//just distance not vector
			tool->step_y = -1;
			tool->to_near_y = (tool->player->pos.y - tool->focus_y)*tool->to_next_y;
		}
		else
		{
			//down
			tool->step_y = 1;
			tool->to_near_y = (tool->focus_y + 1.0 -tool->player->pos.y)*tool->to_next_y;
		}
		tool->is_hit = 0;
		while(!tool->is_hit)
		{
			if(tool->to_near_x < tool->to_near_y)
			{
				tool->to_near_x += tool->to_next_x;
				tool->focus_x += tool->step_x;
				if(tool->ray_x > 0)
					tool->side = 1;
				else
					tool->side = 3;
			}
			else
			{
				tool->to_near_y += tool->to_next_y;
				tool->focus_y += tool->step_y;
				if(tool->ray_y > 0)
					tool->side = 0;
				else
					tool->side = 2;
			}
			if(tool->map->map[tool->focus_y][tool->focus_x] == '1')
				tool->is_hit = 1;
		}
		if(tool->side == 1 || tool->side == 3)
			tool->ver_distance = tool->to_near_x - tool->to_next_x;
		else
			tool->ver_distance = tool->to_near_y - tool->to_next_y;
		//ここあんまいみわからん
		tool->line_height = (int)(W_HEIGHT / tool->ver_distance);
		tool->pix_start = -tool->line_height / 2 + W_HEIGHT / 2;
		tool->pix_end = tool-> line_height / 2 + W_HEIGHT / 2;
		tool->pix_top =tool->pix_start;
		if (tool->pix_start < 0)
			tool->pix_start = 0;
		if (tool->pix_end < 0)
			tool->pix_end = W_HEIGHT -1;
		if(tool->side == 1 || tool->side == 3)
			tool->wall_x = tool->player->pos.y + tool->ver_distance*tool->ray_y;
		else
			tool->wall_x = tool->player->pos.x + tool->ver_distance*tool->ray_x;
		tool->wall_x -= floor((tool->wall_x)); //少数部分
		tool->img_x = (int)(tool->wall_x*(double)(tool->map->image[tool->side].width));
		if(tool->side == 0 || tool->side == 3)
			tool->img_x = tool->map->image[tool->side].width - tool->img_x - 1;
		int y = 0;
		while(y < W_HEIGHT)
		{
			if(y < tool->pix_start)
				set_color(&tool->vars->img.addr[y*tool->vars->img.line_length + x*tool->vars->img.bits_per_pixel / 8],tool->map->ceiling);
			else if (y < tool->pix_end)
			{
				tool->img_y = (y - tool->pix_top )/ ((double)(tool->pix_end-tool->pix_top)/(double)tool->map->image[tool->side].height);
				tool->color = get_color(&tool->map->image[tool->side].addr[tool->img_y*tool->map->image[tool->side].line_length + tool->img_x*(tool->map->image[tool->side].bits_per_pixel / 8)]);
				set_color(&tool->vars->img.addr[y*tool->vars->img.line_length + x*tool->vars->img.bits_per_pixel / 8],tool->color);
			}
			else
				set_color(&tool->vars->img.addr[y*tool->vars->img.line_length + x*tool->vars->img.bits_per_pixel / 8],tool->map->floor);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(tool->vars->mlx,tool->vars->win,tool->vars->img.img,0,0);
}
