# include "so_long.h"

t_verif	verif_init(void)
{
	t_verif	check;

	check.exit = 0;
	check.player = 0;
	check.collectible = 0;
	return (check);
}


int	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
        return (return_failure("Error. Could not initialiaze t_map."));
	printf("%s%ld\n", "size of map 0 = ", sizeof(t_map));
	/*data->map_info = malloc(sizeof(t_map_info));
	if (!data->map_info)
		return ;
	init_south_north_and_player(data);
	init_east_west(data);
	init_ray(data);
	init_img(data);*/
	data->map->map = NULL;
	//data->map->map_2 = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	/*data->map->space_in_map_2 = 0;
	data->map_info->no_texture = NULL;
	data->map_info->so_texture = NULL;
	data->map_info->we_texture = NULL;
	data->map_info->ea_texture = NULL;
	data->map->player.p_pos.x = 0;
	data->map->player.p_pos.y = 0;
	data->map->gap = 0;
	data->map->is_map = 0;*/
    return (SUCCESS);
}
