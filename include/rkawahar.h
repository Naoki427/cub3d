#ifndef RKAWAHAR_H
# define RKAWAHAR_H

typedef struct s_info
{
	char	*noth;
	char	*south;
	char	*east;
	char	*west;
	int		floorling[3];
	int		ceiling[3];
	char	*map;
}			t_info;

#endif