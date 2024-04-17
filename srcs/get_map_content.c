# include "so_long.h"

int	check_get_next_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int		get_number_of_lines(char *s)
{
	int i;
	int fd2;
	char *line;

	i = 0;
	fd2 = open(s, O_RDONLY);
	if (fd2 < 0)
	{
		ft_printf("%s", "Error. Open map.ber failed.");
		return (FAILURE);
	}
	line = get_next_line(fd2);
	while (line != NULL)
	{
		if (check_get_next_line(line) == SUCCESS)
		{
			i++;
		}
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
	printf("%s%d", "number of line in file = ", i);
	return (i);
}


t_map	*reduce_get_map(t_data *data, int fd)
{
	char	*line;
	int		i;

	// Allouer suffisamment d'espace pour stocker toutes les lignes du fichier
	data->map->map = ft_calloc(data->map->count_line + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (check_get_next_line(line) == SUCCESS)
		{
			if (i < data->map->count_line)
			{
				// Copier la ligne dans le tableau
				data->map->map[i] = strdup_no_n(line);
				i++;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (data->map);
}


t_vector	get_map_size(t_data *data)//char **full_map, t_vector size)
{
	int			i;
	int			j;
	t_vector	map_size;

	i = 0;
	j = 0;
	while (data->map->map[i])
	{
		while (data->map->map[i][j])
			j++;
		if (data->map->map[i][j] == 'P')
		{
			data->character_pos.x = j * 100;
			data->character_pos.y = i * 100;
		}
		i++;
	}
	printf("%d\n", j);
	printf("%d\n", i);
	map_size.x = j * 100;
	map_size.y = i * 100;
	return (map_size);
}

t_map	*get_map(char *s, t_data *data)
{
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		free_data(data);
		ft_printf("%s", "Error. Open map.ber failed ici.");
		return (NULL);
	}
	else
	{
		data->map->count_line = get_number_of_lines(s);
		if (data->map->count_line == FAILURE)
		{
			free_data(data);
			return (NULL);
		}
		data->map = reduce_get_map(data, fd);
		data->map->map_max_size = get_map_size(data);
	}
	return (data->map);
}
