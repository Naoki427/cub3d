/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:29:05 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/28 17:56:12 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_color	get_color(char *addr)
{
	t_color	color;

	color.r = addr[0];
	color.g = addr[1];
	color.b = addr[2];
	return (color);
}

void	set_color(char *addr, t_color color)
{
	addr[0] = color.r;
	addr[1] = color.g;
	addr[2] = color.b;
}
