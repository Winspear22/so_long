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

int	check_line_content(t_map *map, t_data *data)
{
	t_verif	check;

	check = verif_init();
    (void)check;
    (void)map;
    (void)data;
    if (check_filled_lines(map->map, &check, data) == FAILURE)
		return (return_failure("Error parsing.\n"));
	return (SUCCESS);

}