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

t_map	*reduce_count_line(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (check_get_next_line(line) == SUCCESS)
		{
			if (i <= 5)
			{
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

	i = -1;
	j = -1;
	while (data->map->map[++i])
	{
		while (data->map->map[i][++j])
			j++;
		i++;
	}
	map_size.x = j * 100;
	map_size.y = i * 100;
	return (map_size);
}

t_map	*count_line(char *s, t_data *data)
{
	int		fd;

	data->map->map = ft_calloc(6 + 1, sizeof(char *));
	if (!(data->map->map))
		return (NULL);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_printf("%s", "Error. Open map.ber failed.");
	else
	{
		data->map = reduce_count_line(data, fd);
		data->map->map_max_size = get_map_size(data);
	}
	return (data->map);
}
