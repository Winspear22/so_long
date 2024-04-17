# include "so_long.h"

t_verif	verif_init(void)
{
	t_verif	check;

	check.exit = 0;
	check.player = 0;
	check.collectible = 0;
	return (check);
}

void	init_img(t_data *data)
{
	data->screen.bpp = 0;
	data->screen.height = 0;
	data->screen.width = 0;
	data->screen.endian = 0;
	data->screen.line = 0;
	data->screen.status = 0;
	data->screen.img = NULL;
	data->screen.addr = NULL;
}

void	init_floor_walls_texture(t_data *data)
{
	data->floor_texture.bpp = 0;
	data->floor_texture.height = 0;
	data->floor_texture.width = 0;
	data->floor_texture.endian = 0;
	data->floor_texture.line = 0;
	data->floor_texture.status = 0;
	data->floor_texture.img = NULL;
	data->floor_texture.addr = NULL;
	data->walls_texture.bpp = 0;
	data->walls_texture.height = 0;
	data->walls_texture.width = 0;
	data->walls_texture.endian = 0;
	data->walls_texture.line = 0;
	data->walls_texture.status = 0;
	data->walls_texture.img = NULL;
	data->walls_texture.addr = NULL;
	data->character_texture.bpp = 0;
	data->character_texture.height = 0;
	data->character_texture.width = 0;
	data->character_texture.endian = 0;
	data->character_texture.line = 0;
	data->character_texture.status = 0;
	data->character_texture.img = NULL;
	data->character_texture.addr = NULL;
}

void init_collectible_exit(t_data *data)
{
	data->collectible_texture.bpp = 0;
	data->collectible_texture.height = 0;
	data->collectible_texture.width = 0;
	data->collectible_texture.endian = 0;
	data->collectible_texture.line = 0;
	data->collectible_texture.status = 0;
	data->collectible_texture.img = NULL;
	data->collectible_texture.addr = NULL;
	data->exit_texture.bpp = 0;
	data->exit_texture.height = 0;
	data->exit_texture.width = 0;
	data->exit_texture.endian = 0;
	data->exit_texture.line = 0;
	data->exit_texture.status = 0;
	data->exit_texture.img = NULL;
	data->exit_texture.addr = NULL;

}

int	init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
        return (return_failure("Error. Could not initialiaze t_map."));
	printf("%s%ld\n", "size of map = ", sizeof(t_map));
	init_img(data);
	init_floor_walls_texture(data);
	init_collectible_exit(data);
	data->map->map = NULL;
	data->map->fd = 0;
	data->map->count_line = 0;
	data->walls_texture_name = NULL;
	data->floor_texture_name = NULL;
	data->character_pos.x = 0;
	data->character_pos.y = 0;
    return (SUCCESS);
}
