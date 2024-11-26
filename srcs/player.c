/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:38:01 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/26 17:30:12 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_player(t_player *player, t_info *init_info, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	player->move_flg = 0;
	player->turn_flg = 0;
	player->front.x = 0;
	player->front.y = 0;
	player->map = map;
	while (init_info->map[i])
	{
		j = 0;
		while (init_info->map[i][j])
		{
			init_posision(player, init_info, i, j);
			j++;
		}
		i++;
	}
	player->right = rotate(player->front, M_PI / 2);
}

void	init_posision(t_player *player, t_info *init_info, int i, int j)
{
	if (init_info->map[i][j] == 'N' || init_info->map[i][j] == 'W'
		|| init_info->map[i][j] == 'S' || init_info->map[i][j] == 'E')
	{
		player->pos.x = j + 0.5;
		player->pos.y = i + 0.5;
		if (init_info->map[i][j] == 'N')
			player->front.y = -1;
		if (init_info->map[i][j] == 'W')
			player->front.x = -1;
		if (init_info->map[i][j] == 'S')
			player->front.y = 1;
		if (init_info->map[i][j] == 'E')
			player->front.x = 1;
	}
}
