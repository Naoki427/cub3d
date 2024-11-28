/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:59:29 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/28 17:55:46 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_vector	reverse(t_vector vec)
{
	t_vector	result;

	result.x = -vec.x;
	result.y = -vec.y;
	return (result);
}

t_vector	rotate(t_vector vec, double rad)
{
	t_vector	result;

	result.x = vec.x * cos(rad) - vec.y * sin(rad);
	result.y = vec.x * sin(rad) + vec.y * cos(rad);
	return (result);
}
