# include "so_long.h"

int	check_file_content(char *argv, t_data *data)
{
    data->map = get_map(argv, data);
	if (data->map == NULL)
		return (FAILURE);
	if (check_map_content(data->map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}