/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:14:12 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/26 18:20:22 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	key_press(int keycode, t_tool *tool)
{
	if (keycode == KEY_W)
		tool->player->move_flg = UP;
	if (keycode == KEY_A)
		tool->player->move_flg = LEFT;
	if (keycode == KEY_S)
		tool->player->move_flg = DOWN;
	if (keycode == KEY_D)
		tool->player->move_flg = RIGHT;
	if (keycode == KEY_LEFT)
		tool->player->turn_flg = ROT_LEFT;
	if (keycode == KEY_RIGHT)
		tool->player->turn_flg = ROT_RIGHT;
	if (keycode == ON_DESTROY)
	{
		mlx_destroy_window(tool->vars->mlx, tool->vars->win);
		exit(0);
	}
	return (0);
}

static void	move_player(t_player *player, t_vector vec)
{
	double	space_x;
	double	space_y;

	if (vec.x > 0)
		space_x = 0.2;
	else
		space_x = -0.2;
	if (vec.y > 0)
		space_y = 0.2;
	else
		space_y = -0.2;
	if (player->map->map[(int)floor(player->pos.y)][(int)floor(player->pos.x
			+ vec.x * MOV_SPEED + space_x)] != '1')
		player->pos.x += vec.x * MOV_SPEED;
	if (player->map->map[(int)floor(player->pos.y + vec.y * MOV_SPEED
				+ space_y)][(int)floor(player->pos.x)] != '1')
		player->pos.y += vec.y * MOV_SPEED;
}

static void	set_fov(t_tool *tool, double rad)
{
	double	old_fov_x;

	old_fov_x = tool->fov_x;
	tool->fov_x = tool->fov_x * cos(rad) - tool->fov_y * sin(rad);
	tool->fov_y = old_fov_x * sin(rad) + tool->fov_y * cos(rad);
}

static void	handle_move_flg(t_tool *tool)
{
	if (tool->player->move_flg == UP)
	{
		move_player(tool->player, tool->player->front);
		tool->player->move_flg = 0;
		do_ray_cast(tool);
	}
	else if (tool->player->move_flg == RIGHT)
	{
		move_player(tool->player, tool->player->right);
		tool->player->move_flg = 0;
		do_ray_cast(tool);
	}
	else if (tool->player->move_flg == DOWN)
	{
		move_player(tool->player, reverse(tool->player->front));
		tool->player->move_flg = 0;
		do_ray_cast(tool);
	}
	else if (tool->player->move_flg == LEFT)
	{
		move_player(tool->player, reverse(tool->player->right));
		tool->player->move_flg = 0;
		do_ray_cast(tool);
	}
}

int	loop_hook(t_tool *tool)
{
	handle_move_flg(tool);
	if (tool->player->turn_flg == ROT_RIGHT)
	{
		tool->player->front = rotate(tool->player->front, M_PI / 6);
		set_fov(tool, M_PI / 6);
		tool->player->right = rotate(tool->player->front, M_PI / 2);
		tool->player->turn_flg = 0;
		do_ray_cast(tool);
	}
	else if (tool->player->turn_flg == ROT_LEFT)
	{
		tool->player->front = rotate(tool->player->front, -M_PI / 6);
		set_fov(tool, -M_PI / 6);
		tool->player->right = rotate(tool->player->front, M_PI / 2);
		tool->player->turn_flg = 0;
		do_ray_cast(tool);
	}
	return (0);
}
