/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:53:52 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/24 00:03:10 by nyoshimi         ###   ########.fr       */
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



void do_ray_cast(t_player *player,t_map *map,t_tool *tool,t_vars *vars)
{
	int x = 0;
	while(x < W_WIDTH)
	{
		tool->cameraX = 2*x/ (double)W_WIDTH -1;
		tool->rayX = player->front.x + tool->fovX*tool->cameraX;
		tool->rayY = player->front.y + tool->fovY*tool->cameraX;
		tool->focusX = player->pos.x;
		tool->focusY = player->pos.y;
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
			tool->toNearX = (player->pos.x - tool->focusX)*tool->toNextX;
		}
		else
		{
			//down
			tool->stepX = 1;
			tool->toNearX = (tool->focusX + 1.0 -player->pos.x)*tool->toNextX;
		}
		if(tool->rayY < 0)
		{
			//up
			//just distance not vector
			tool->stepY = -1;
			tool->toNearY = (player->pos.y - tool->focusY)*tool->toNextY;
		}
		else
		{
			//down
			tool->stepY = 1;
			tool->toNearY = (tool->focusY + 1.0 -player->pos.y)*tool->toNextY;
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
			if(map->map[tool->focusY][tool->focusX] == '1')
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
		if (tool->pixStart < 0)
			tool->pixStart = 0;
		tool->pixEnd = tool-> lineHeight / 2 + W_HEIGHT / 2;
		if (tool->pixEnd < 0)
			tool->pixEnd = W_HEIGHT -1;
		if(tool->side == 1 || tool->side == 3)
			tool->wallX = player->pos.y + tool->verDistance*tool->rayY;
		else
			tool->wallX = player->pos.x + tool->verDistance*tool->rayX;
		tool->wallX -= floor((tool->wallX)); //少数部分
		tool->imgX = (int)(tool->wallX*(double)(map->image[tool->side].width));
		// if(tool->side == 2 || tool->side == 3)
		// 	tool->imgX = map->image[tool->side].width - tool->imgX - 1;
		int y = 0;
		while(y < W_HEIGHT)
		{
			if(y < tool->pixStart)
				set_color(&vars->img.addr[y*vars->img.line_length + x*vars->img.bits_per_pixel / 8],map->ceiling);
			else if (y < tool->pixEnd)
			{
				tool->imgY = (y - tool->pixStart )/ ((double)(tool->pixEnd-tool->pixStart)/(double)map->image[tool->side].height);
				tool->color = get_color(&map->image[tool->side].addr[tool->imgY*map->image[tool->side].line_length + tool->imgX*(map->image[tool->side].bits_per_pixel / 8)]);
				set_color(&vars->img.addr[y*vars->img.line_length + x*vars->img.bits_per_pixel / 8],tool->color);
			}
			else
				set_color(&vars->img.addr[y*vars->img.line_length + x*vars->img.bits_per_pixel / 8],map->floor);
			y++;
		}
		x++;
	}
	if(!mlx_put_image_to_window(vars->mlx,vars->win,vars->img.img,0,0))
		put_error_message("mlx_put_image_to_window");
}

int key_press(int keycode, t_player *player)
{
	if(keycode == KEY_W)
		player->move_flg = UP;
	if(keycode == KEY_A)
		player->move_flg = LEFT;
	if(keycode == KEY_S)
		player->move_flg = DOWN;
	if(keycode == KEY_D)
		player->move_flg = RIGHT;
	if(keycode == KEY_LEFT)
		player->turn_flg = ROT_LEFT;
	if(keycode == KEY_RIGHT)
		player->turn_flg = ROT_RIGHT;
	return (0);
}

int key_release(int keycode, t_player *player)
{
	if(keycode == KEY_W)
		player->move_flg = 0;
	if(keycode == KEY_A)
		player->move_flg = 0;
	if(keycode == KEY_S)
		player->move_flg = 0;
	if(keycode == KEY_D)
		player->move_flg = 0;
	if(keycode == KEY_LEFT)
		player->turn_flg = 0;
	if(keycode == KEY_RIGHT)
		player->turn_flg = 0;
	return (0);
}

void move_player(t_player *player,t_vector vec)
{
	if(player->map->map[(int)floor(player->pos.x + vec.x*MOV_SPEED + 0.1)][(int)floor(player->pos.y)] != '1')
		player->pos.x += vec.x*MOV_SPEED;
	if(player->map->map[(int)floor(player->pos.x )][(int)floor(player->pos.y+ vec.x*MOV_SPEED + 0.1)] != '1')
	player->pos.y += vec.y*MOV_SPEED;
}
int loop_hook(t_player *player)
{
	if(player->move_flg == UP)
		move_player(player,player->front);
	return(0);
}