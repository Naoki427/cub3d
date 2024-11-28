/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:07:31 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/28 20:36:06 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	put_error_message(char *message)
{
	printf("fatal error: %s\n", message);
	exit(EXIT_FAILURE);
}

int	close_window(t_tool *tool)
{
	mlx_destroy_window(tool->vars->mlx, tool->vars->win);
	exit(0);
}
