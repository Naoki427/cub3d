/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkawahar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoshimi <nyoshimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:43:14 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/11/28 17:49:34 by nyoshimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RKAWAHAR_H
# define RKAWAHAR_H

typedef struct s_info
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*flooring;
	int		*ceiling;
	char	**map;
}			t_info;

size_t	ft_strlen(char *str);
t_info	analysis_file(int fd);
t_info	init_info(void);
int		check_info(t_info info);
int		ft_isspace(char c);
char	*ft_strcpy(char *str);
void	printf_exit(char *str);
char	**insert_map(char *str, int fd);
void	ft_insertion(char *str, int *nums);
void	ft_free(char **str);
char	**check_map(t_info info);
char	*set_space(int x);
char	*copy_map_str(int x, char *str);
void	back_track(char **map);
void	free_info(t_info info);

void	check_struct(t_info info);

#endif