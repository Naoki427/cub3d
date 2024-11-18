/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:42:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/11/18 14:50:39 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Arguments error: write a filename.\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("File error: %s: cannot open the file\n", av[1]);
	}
}