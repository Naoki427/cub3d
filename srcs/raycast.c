/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:53:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/26 17:07:40 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_color get_color(char *addr)
{
	t_color color;
	color.r = addr[0];
	color.g = addr[1];
	color.b = addr[2];
	return (color);
}

void set_color(char *addr,t_color color)
{
	addr[0] = color.r;
	addr[1] = color.g;
	addr[2] = color.b;
}

void do_ray_cast(t_tool *tool)
{
	int x = 0;
	while(x < W_WIDTH)
	{
		tool->cameraX = 2*x/ (double)W_WIDTH -1;
		tool->rayX = tool->player->front.x + tool->fovX*tool->cameraX;
		tool->rayY = tool->player->front.y + tool->fovY*tool->cameraX;
		tool->focusX = tool->player->pos.x;
		tool->focusY = tool->player->pos.y;
		if(tool->rayX == 0)
			tool->toNextX = __INT_MAX__;
		else if(tool->rayX > 0)
			tool->toNextX = 1/tool->rayX;
		else
			tool->toNextX = -1/tool->rayX;
		if(tool->rayY == 0)
			tool->toNextY = __INT_MAX__;
		else if(tool->rayY > 0)
			tool->toNextY= 1/tool->rayY;
		else
			tool->toNextY = -1/tool->rayY;
		if(tool->rayX < 0)
		{
			//up
			//just distance not vector
			tool->stepX = -1;
			tool->toNearX = (tool->player->pos.x - tool->focusX)*tool->toNextX;
		}
		else
		{
			//down
			tool->stepX = 1;
			tool->toNearX = (tool->focusX + 1.0 -tool->player->pos.x)*tool->toNextX;
		}
		if(tool->rayY < 0)
		{
			//up
			//just distance not vector
			tool->stepY = -1;
			tool->toNearY = (tool->player->pos.y - tool->focusY)*tool->toNextY;
		}
		else
		{
			//down
			tool->stepY = 1;
			tool->toNearY = (tool->focusY + 1.0 -tool->player->pos.y)*tool->toNextY;
		}
		tool->is_hit = 0;
		while(!tool->is_hit)
		{
			if(tool->toNearX < tool->toNearY)
			{
				tool->toNearX += tool->toNextX;
				tool->focusX += tool->stepX;
				if(tool->rayX > 0)
					tool->side = 1;
				else
					tool->side = 3;
			}
			else
			{
				tool->toNearY += tool->toNextY;
				tool->focusY += tool->stepY;
				if(tool->rayY > 0)
					tool->side = 0;
				else
					tool->side = 2;
			}
			if(tool->map->map[tool->focusY][tool->focusX] == '1')
			{
				tool->is_hit = 1;
			}
		}
		if(tool->side == 1 || tool->side == 3)
			tool->verDistance = tool->toNearX - tool->toNextX;
		else
			tool->verDistance = tool->toNearY - tool->toNextY;
		//ここあんまいみわからん
		tool->lineHeight = (int)(W_HEIGHT / tool->verDistance);
		tool->pixStart = -tool->lineHeight / 2 + W_HEIGHT / 2;
		tool->pixEnd = tool-> lineHeight / 2 + W_HEIGHT / 2;
		tool->pixTop =tool->pixStart;
		if (tool->pixStart < 0)
			tool->pixStart = 0;
		if (tool->pixEnd < 0)
			tool->pixEnd = W_HEIGHT -1;
		if(tool->side == 1 || tool->side == 3)
			tool->wallX = tool->player->pos.y + tool->verDistance*tool->rayY;
		else
			tool->wallX = tool->player->pos.x + tool->verDistance*tool->rayX;
		tool->wallX -= floor((tool->wallX)); //少数部分
		tool->imgX = (int)(tool->wallX*(double)(tool->map->image[tool->side].width));
		if(tool->side == 0 || tool->side == 3)
			tool->imgX = tool->map->image[tool->side].width - tool->imgX - 1;
		int y = 0;
		while(y < W_HEIGHT)
		{
			if(y < tool->pixStart)
				set_color(&tool->vars->img.addr[y*tool->vars->img.line_length + x*tool->vars->img.bits_per_pixel / 8],tool->map->ceiling);
			else if (y < tool->pixEnd)
			{
				tool->imgY = (y - tool->pixTop )/ ((double)(tool->pixEnd-tool->pixTop)/(double)tool->map->image[tool->side].height);
				tool->color = get_color(&tool->map->image[tool->side].addr[tool->imgY*tool->map->image[tool->side].line_length + tool->imgX*(tool->map->image[tool->side].bits_per_pixel / 8)]);
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
