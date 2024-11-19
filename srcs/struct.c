/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:50 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/18 20:48:44 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

t_info	init_info(void)
{
	t_info	ans;
	int		i;

	ans.north = NULL;
	ans.south = NULL;
	ans.east = NULL;
	ans.west = NULL;
	ans.map = NULL;
	i = 0;
	ans.ceiling = (int *)malloc(sizeof(int) * 3);
	ans.flooring = (int *)malloc(sizeof(int) * 3);
	if (!ans.ceiling || !ans.flooring)
		printf_exit("malloc error");
	while (i < 3)
	{
		ans.ceiling[i] = -1;
		ans.flooring[i++] = -1;
	}
	return (ans);
}

int	check_info(t_info info)
{
	int	ans;
	int	i;

	ans = 0;
	if (!info.north || !info.south)
		ans = 1;
	if (!info.east || !info.west)
		ans = 1;
	i = 0;
	while (i < 3)
	{
		if (info.ceiling[i] == -1 || info.flooring[i] == -1)
			ans = 1;
		i++;
	}
	if (!info.map)
		ans = 1;
	return (ans);
}
