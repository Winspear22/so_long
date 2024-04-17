
# include "so_long.h"

t_vector	ft_player_pos(char **tab)
{
	int			i;
	int			j;
	t_vector	player_pos;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				player_pos.x = j;
				player_pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

t_img	ft_new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.img = 0;
	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img,
			&img.bpp, &img.line, &img.endian);
	return (img);
}


int	ft_create_character(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->character_texture.img == NULL)
		data->character_texture = ft_new_sprite(mlx, "sprites/gokuu.xpm");
	mlx_put_image_to_window(mlx, window,
		data->character_texture.img, k, l);
    k = k + 100;
    return (k);
}

int	ft_draw_walls(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->walls_texture.img == NULL)
    	data->walls_texture = ft_new_sprite(mlx, "sprites/wallhd.xpm"); 
	mlx_put_image_to_window(mlx, window, data->walls_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_grass(void *mlx, void *window, int k, int l, t_data *data)
{	
	if (data->floor_texture.img == NULL)
    	data->floor_texture = ft_new_sprite(mlx, "sprites/grass.xpm"); 
	mlx_put_image_to_window(mlx, window, data->floor_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_items(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->collectible_texture.img == NULL)
		data->collectible_texture = ft_new_sprite(mlx, "sprites/senzu.xpm"); 
	mlx_put_image_to_window(mlx, window, data->collectible_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_exit(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->exit_texture.img == NULL)
    	data->exit_texture = ft_new_sprite(mlx, "sprites/freezer.xpm"); 
	mlx_put_image_to_window(mlx, window, data->exit_texture.img,
    k, l);
	k = k + 100;
	return (k);
}


int	ft_draw(t_data *data)//(char **tab, void *mlx, void *window, t_data *data)
{
	t_check_map	map;

	map.i = -1;
	map.j = -1;
	map.k = 0;
	map.l = 0;
	while (data->map->map[++map.i])
	{
		while (data->map->map[map.i][++map.j])
		{
			if (data->map->map[map.i][map.j] == '1')
				map.k = ft_draw_walls(data->mlx_ptr, data->win_ptr, map.k, map.l, data);
			else if (data->map->map[map.i][map.j] == '0')
				map.k = ft_draw_grass(data->mlx_ptr, data->win_ptr, map.k, map.l, data);
			if (data->map->map[map.i][map.j] == 'C')
				map.k = ft_draw_items(data->mlx_ptr, data->win_ptr, map.k, map.l, data);
			if (data->map->map[map.i][map.j] == 'E')
				map.k = ft_draw_exit(data->mlx_ptr, data->win_ptr, map.k, map.l, data);
			else if (data->map->map[map.i][map.j] == 'P')
				map.k = ft_create_character(data->mlx_ptr, data->win_ptr, map.k, map.l, data);
		}
		map.j = -1;
		map.l = map.l + 100;
		map.k = 0;
	}
	return SUCCESS;
}

int	close_redx(t_data *data)
{
	if (data->win_ptr)
	{
		//free_map_info(data->map_info, data);
		free_data(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		data->win_ptr = NULL;
	}
	free(data->mlx_ptr);
	if (data != NULL)
		free(data);
	exit(0);
}

int loop(t_data *data)
{
    //ft_draw(data->map->map, data->mlx_ptr, data->win_ptr, data);
	mlx_loop_hook(data->mlx_ptr, ft_draw, data);
    mlx_hook(data->win_ptr, 17, 0L, &close_redx, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
	t_data	*data;

	data = NULL;
    if (!(*env))
		return (return_failure("Error. No environment."));
    if (check_arguments(argc, argv[1]) == FAILURE)
		return (FAILURE);
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
	init_data(data);
	if (check_file_content(argv[1], data) == FAILURE)
	{
		free_data(data);
        free(data); // Libération de la mémoire pour data
		ft_printf("%s%s%s", RED, "Error in the second step.", RESET);
		return (FAILURE);
	}
	if (init_window(data) == FAILURE)
		return (FAILURE);
	/*if (create_textures_wall(data) == FAILURE)
		return (FAILURE);*/
	//ft_draw(data);
    ft_printf("%s%s%s", GREEN, "réussite", RESET);
	loop(data);		
    return (SUCCESS);
}