# include "so_long.h"

int	check_file_content(char *argv, t_data *data)
{
    data->map = get_map(argv, data);
	if (data->map == NULL)
		return (FAILURE);
	int i = 0;
	while (data->map->map[i])
	{
		ft_printf("%s\n", data->map->map[i]);
		i++;
	}
	ft_printf("%s", "Taille de la map\n");
	ft_printf("%s%d\n%s%d\n", "x = ", data->map->map_max_size.x, "y = ", data->map->map_max_size.y);
	if (check_map_content(data->map) == FAILURE)
		return (FAILURE);
	//	data->map_info = get_all_map_info(data);

	return (SUCCESS);

}