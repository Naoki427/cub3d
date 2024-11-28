/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:05:10 by nyoshimi          #+#    #+#             */
/*   Updated: 2024/11/28 20:29:42 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	start_ray_cast(t_info *info)
{
	t_vars		vars;
	t_player	player;
	t_map		map;
	t_tool		tool;

	init_window(&vars);
	init_image(&vars, info, &map);
	suceed_map(info, &map);
	init_player(&player, info, &map);
	init_tool(&tool, &player, &vars, &map);
	do_ray_cast(&tool);
	mlx_loop_hook(vars.mlx, loop_hook, &tool);
	mlx_key_hook(vars.win, &key_press, &tool);
	mlx_hook(vars.win, 17, 0, close_window, &tool);
	mlx_loop(vars.mlx);
}

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		put_error_message("mlx_init");
	vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (!vars->win)
		put_error_message("mlx_new_window");
	vars->img.img = mlx_new_image(vars->mlx, W_WIDTH, W_HEIGHT);
	if (!vars->img.img)
		put_error_message("mlx_new_image");
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (!vars->img.addr)
		put_error_message("mlx_get_data_addr");
}

void	suceed_map(t_info *info, t_map *map)
{
	map->map = info->map;
	map->ceiling.r = info->ceiling[0];
	map->ceiling.g = info->ceiling[1];
	map->ceiling.b = info->ceiling[2];
	map->floor.r = info->flooring[0];
	map->floor.g = info->flooring[1];
	map->floor.b = info->flooring[2];
}

void	init_image(t_vars *vars, t_info *info, t_map *map)
{
	int	i;

	i = 0;
	map->image[0].img = mlx_xpm_file_to_image(vars->mlx, info->north,
			&(map->image[0].width), &(map->image[0].height));
	map->image[1].img = mlx_xpm_file_to_image(vars->mlx, info->west,
			&(map->image[1].width), &(map->image[1].height));
	map->image[2].img = mlx_xpm_file_to_image(vars->mlx, info->south,
			&(map->image[2].width), &(map->image[2].height));
	map->image[3].img = mlx_xpm_file_to_image(vars->mlx, info->east,
			&(map->image[3].width), &(map->image[3].height));
	if (!map->image[0].img || !map->image[1].img || !map->image[2].img
		|| !map->image[3].img)
		put_error_message("mlx_xpm_file_to_image");
	while (i < 4)
	{
		map->image[i].addr = mlx_get_data_addr(map->image[i].img,
				&(map->image[i].bits_per_pixel), &(map->image[i].line_length),
				&(map->image[i].endian));
		i++;
	}
	if (!map->image[0].addr || !map->image[1].addr || !map->image[2].addr
		|| !map->image[3].addr)
		put_error_message("mlx_get_data_addr");
}

void	init_tool(t_tool *tool, t_player *player, t_vars *vars, t_map *map)
{
	tool->fov_x = 0;
	tool->fov_y = 0;
	if (player->front.y == 1)
		tool->fov_x = -0.66;
	else if (player->front.y == -1)
		tool->fov_x = 0.66;
	else if (player->front.x == 1)
		tool->fov_y = 0.66;
	else if (player->front.x == -1)
		tool->fov_y = -0.66;
	tool->time = 0;
	tool->old_time = 0;
	tool->player = player;
	tool->map = map;
	tool->vars = vars;
}
