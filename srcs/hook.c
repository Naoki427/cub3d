/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:14:12 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/24 02:12:41 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int key_press(int keycode, t_player *player)
{
	printf("keycode = %d\n",keycode);
	if(keycode == KEY_W)
	{
		printf("a");
		player->move_flg = UP;
	}
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
	printf("keycode = %d\n",keycode);
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
	printf("x = %d, y = %d\n",(int)floor(player->pos.x + vec.x*MOV_SPEED + 0.1),(int)floor(player->pos.y+ vec.x*MOV_SPEED + 0.1));
	if(player->map->map[(int)floor(player->pos.x + vec.x*MOV_SPEED + 0.1)][(int)floor(player->pos.y)] != '1')
		player->pos.x += vec.x*MOV_SPEED;
	if(player->map->map[(int)floor(player->pos.x )][(int)floor(player->pos.y+ vec.x*MOV_SPEED + 0.1)] != '1')
	player->pos.y += vec.y*MOV_SPEED;
}
int loop_hook(t_tool *tool)
{
	if(tool->player->move_flg == UP)
	{
		move_player(tool->player,tool->player->front);
		tool->player->move_flg = 0;
		do_ray_cast(tool);
	}
	return(0);
}