/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:26 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/18 15:51:20 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub_3d.h"

size_t	ft_strlen(char *str)
{
	int	ans;

	ans = 0;
	while (str[ans])
		ans++;
	return (ans);
}
