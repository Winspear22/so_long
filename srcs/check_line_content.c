# include "so_long.h"


int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] <= 32)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	reduce_fonction_above(char **s_byspa, t_verif *check, char *str,
	t_data *data)
{
    (void)data;
    (void)str;
    (void)check;
	if (s_byspa[1])
	{
		/*if (compare_and_open_line(s_byspa, check, str, data) == -1)
			return (reduce_check_filled_lines(s_byspa));
		if (compare_and_check_number_line(s_byspa, check) == FAILURE)
			return (reduce_check_filled_lines(s_byspa));*/
	}
	if (s_byspa[2])
		return (ret_free(NULL, s_byspa));
	else
		free_tab(s_byspa);
	return (SUCCESS);
}

int	check_filled_lines(char **map, t_verif *check, t_data *data)
{
	int		i;
	char	**s_byspa;

	i = -1;
	s_byspa = NULL;
	while (map[++i])
	{
		if (check_whitespace(map[i]) == SUCCESS)
		{
			s_byspa = ft_split(map[i], ' ');
			if (!s_byspa[1])
				return (ret_free(NULL, s_byspa));
			if (reduce_fonction_above(s_byspa, check, s_byspa[1], data) == -1)
				return (FAILURE);
		}
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

int check_all_elements(t_map *map, t_verif check)
{
	int i;
	int j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				check.player++;
			if (map->map[i][j] == 'E')
				check.exit++;
			if (map->map[i][j] == 'C')
				check.collectible++;
		}
	}
	if (check.player != 1 || check.exit == 0 || check.collectible == 0)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_wall_map_updown(t_map *map)
{
	int	i;
	int	j;
	int	max_y;

	i = -1;
	j = -1;
	max_y = map->map_max_size.y / 100;
	while (map->map && map->map[++i])
	{
		while (map->map[i][++j])
		{
			if ((map->map[0][j] != '1') || (map->map[max_y - 1][j] != '1'))
				return (FAILURE);
		}
		j = 0;
	}
	return (SUCCESS);
}

int	ft_check_wall_map_leftright(t_map *map)
{
	int	i;
	int	j;
	int	max_x;

	i = 0;
	j = 0;
	max_x = map->map_max_size.x / 100;
	while (map->map && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][0] != '1')
				return (FAILURE);
			else if (map->map[i][max_x - 1] != '1')
				return (FAILURE);
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' &&
				map->map[i][j] != 'P' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'E')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_content(t_map *map)
{
	t_verif	check;

	check = verif_init();
	if (ft_check_wall_map_updown(map))
		return (return_failure("Error parsing, there is a problem with walls up-down.\n"));
	if (ft_check_wall_map_leftright(map))
		return (return_failure("Error parsing, there is a problem with walls left-right.\n"));
	if (check_all_elements(map, check) == FAILURE)
		return (return_failure("Error parsing, there is a problem with elements.\n"));
	return (SUCCESS);

}