/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:59:29 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/22 00:55:27 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_vector normarize(t_vector v)
{
	float length;
	t_vector normarized;
	
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	normarized.x = v.x / length;
	normarized.y = v.y / length;
	normarized.z = v.z / length;
	return (normarized);
}

t_vector cross(t_vector a,t_vector b)
{
	t_vector result;
	
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

float distance(t_vector a, t_vector b)
{
	float	result;

	result = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
	return (result);
}

float dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector sum(t_vector o, t_vector p)
{
	t_vector	result;
	
	result.x = p.x + o.x;
	result.y = p.y + o.y;
	result.z = p.z + o.z;
	return (result);
}

t_vector difference(t_vector o, t_vector p)
{
	t_vector	result;
	
	result.x = p.x - o.x;
	result.y = p.y - o.y;
	result.z = p.z - o.z;
	return (result);
}

t_vector product(t_vector o, t_vector p)
{
	t_vector	result;
	
	result.x = p.x * o.x;
	result.y = p.y * o.y;
	result.z = p.z * o.z;
	return (result);
}