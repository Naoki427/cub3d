/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:07:31 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/25 09:08:09 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void put_error_message(char *message)
{
	printf("fatal error: %s\n",message);
	exit(EXIT_FAILURE);
}