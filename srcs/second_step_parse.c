# include "so_long.h"

int	check_file_content(char *argv, t_data *data)
{
	(void)argv;
	(void)data;
    data->map = count_line(argv, data);
	int i = 0;
	while (data->map->map[i])
	{
		ft_printf("%s\n", data->map->map[i]);
		i++;
	}
	if (check_line_content(data->map, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);

}