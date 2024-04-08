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
		data->map = reduce_count_line(data, fd);
	return (data->map);
}

int	check_file_content(char *argv, t_data *data)
{
	(void)argv;
	(void)data;
    data->map = count_line(argv, data);
	
	return (SUCCESS);

}