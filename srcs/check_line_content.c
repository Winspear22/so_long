# include "so_long.h"

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