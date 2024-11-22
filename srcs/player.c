/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:38:01 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/22 01:00:42 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void init_player(t_player *player, t_info *init_info)
{
	int	i;
	int	j;

	i = 0;
	player->move_flg = 0;
	player->turn_flg = 0;
	player->front.x = 0.0f;
	player->front.y = 0.0f;
	player->front.z = 0.0f;
	player->pos.z = 32;
	while(init_info->map[i])
	{
		j = 0;
		while (init_info->map[i][j])
		{
			init_posision(player,init_info,i,j);
			j++;
		}
		i++;
	}
	get_right_and_up_vector(player);
}

void init_posision(t_player *player, t_info *init_info,int i,int j)
{
	if(init_info->map[i][j] == 'N' || init_info->map[i][j] == 'W' 
	|| init_info->map[i][j] == 'S' || init_info->map[i][j] == 'E')
	{
		player->pos.x = j*64 + 32;
		player->pos.y = i*64 + 32;
		if(init_info->map[i][j] == 'N')
			player->front.y = 1.0f;
		if(init_info->map[i][j] == 'W')
			player->front.x = -1.0f;
		if(init_info->map[i][j] == 'S')
			player->front.y = -1.0f;
		if(init_info->map[i][j] == 'E')
			player->front.x = 1.0f;
	}
}

void get_right_and_up_vector(t_player *player)
{
	t_vector world_up;

	world_up.x = 0.0f;
	world_up.y = 0.0f;
	world_up.z = 1.0f;
	player->right = normarize(cross(player->front, world_up));
	player->up = normarize(cross(player->right, player->front));
}