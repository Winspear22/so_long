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
	ft_printf("%s", "Taille de la map\n");
	ft_printf("%s%d\n%s%d\n", "x = ", data->map->map_max_size.x, "y = ", data->map->map_max_size.x);
	if (check_line_content(data->map, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);

}