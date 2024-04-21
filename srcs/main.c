
# include "so_long.h"

int	ft_count_items(char **tab)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	j = 0;
	items = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				items += 1;
			j++;
		}
		i++;
	}
	return (items);
}

t_img	ft_new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.img = 0;
	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img)
	{
		img.status = 1;
        return (img);
	}
	img.addr = mlx_get_data_addr(img.img,
			&img.bpp, &img.line, &img.endian);
	if (!img.addr)
	{
		img.status = 1;
        return (img);
	}	
	return (img);
}

int	close_redx(t_data *data)
{
	if (data->win_ptr)
	{
		free_data(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		data->win_ptr = NULL;
	}
	free(data->mlx_ptr);
	if (data != NULL)
		free(data);
	exit(SUCCESS);
}

void	ft_take(char **tab, t_data *data)
{
	int	items;

	items = 0;
	items = ft_count_items(tab);
	if (data->map->map[data->map->player.p_pos.y][data->map->player.p_pos.x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_texture.img,
   	 		data->map->player.p_pos.y, data->map->player.p_pos.x);
		data->map->map[data->map->player.p_pos.y][data->map->player.p_pos.x] = '0';
		items -= 1;
	}
	if (data->map->map[data->map->player.p_pos.y][data->map->player.p_pos.x] == 'E' && items == 0)
	{
		write(1, "You finished the game, congrats !\n", 35);
		close_redx(data);
	}
}

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

int	ft_draw_walls(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->walls_texture.img == NULL)
	{
    	data->walls_texture = ft_new_sprite(mlx, "sprites/wallhd.xpm");
		if (data->walls_texture.img == NULL || data->walls_texture.addr == NULL)
			return (FAILURE);
	}
	mlx_put_image_to_window(mlx, window, data->walls_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_grass(void *mlx, void *window, int k, int l, t_data *data)
{	
	if (data->floor_texture.img == NULL)
	{
    	data->floor_texture = ft_new_sprite(mlx, "sprites/grass.xpm");
		if (data->floor_texture.img == NULL || data->floor_texture.addr == NULL)
			return (FAILURE);
	}
	mlx_put_image_to_window(mlx, window, data->floor_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_items(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->collectible_texture.img == NULL)
	{
    	data->collectible_texture = ft_new_sprite(mlx, "sprites/senzu.xpm");
		if (data->collectible_texture.img == NULL || data->collectible_texture.addr == NULL)
			return (FAILURE);
	}
	mlx_put_image_to_window(mlx, window, data->collectible_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_exit(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->exit_texture.img == NULL)
	{
    	data->exit_texture = ft_new_sprite(mlx, "sprites/freezer.xpm");
		if (data->exit_texture.img == NULL || data->exit_texture.addr == NULL)
			return (FAILURE);
	}
	mlx_put_image_to_window(mlx, window, data->exit_texture.img,
    k, l);
	k = k + 100;
	return (k);
}

int	ft_create_character(void *mlx, void *window, int k, int l, t_data *data)
{
	if (data->map->player_switch == 0)
	{
		data->character_texture = ft_new_sprite(mlx, "sprites/gokuu.xpm");
		data->map->player_switch = 1;
		mlx_put_image_to_window(mlx, window,
		data->character_texture.img, k, l);
    	k = k + 100;
	}
	else
	{
    	data->character_texture = ft_new_sprite(mlx, "sprites/gokuu.xpm"); 
		mlx_put_image_to_window(mlx, window, data->floor_texture.img,
   	 		k, l);
		k = k + 100;	
	}
    return (k);
}

int	ft_draw(t_data *data)
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
			if (map.k == FAILURE)			
				ret_free_txt("Error with the texture generation.", data);
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

int	press_keyboard(int key, t_data *data)
{
	if (key == XK_w)
		data->map->player.gamplay.forward = 1;
	else if (key == XK_s)
		data->map->player.gamplay.backward = 1;
	else if (key == XK_a)
		data->map->player.gamplay.left = 1;
	else if (key == XK_d)
		data->map->player.gamplay.right = 1;
	else if (key == XK_Left)
		data->map->player.gamplay.look_left = 1;
	else if (key == XK_Right)
		data->map->player.gamplay.look_right = 1;
	else if (key == XK_Escape)
		data->map->player.gamplay.escape = 1;
	return (SUCCESS);
}

int	release_keyboard(int key, t_data *data)
{
	if (key == XK_w)
		data->map->player.gamplay.forward = 0;
	else if (key == XK_s)
		data->map->player.gamplay.backward = 0;
	else if (key == XK_a)
		data->map->player.gamplay.left = 0;
	else if (key == XK_d)
		data->map->player.gamplay.right = 0;
	else if (key == XK_Left)
		data->map->player.gamplay.look_left = 0;
	else if (key == XK_Right)
		data->map->player.gamplay.look_right = 0;
	else if (key == XK_Escape)
		data->map->player.gamplay.escape = 0;
	return (SUCCESS);
}

void	ft_refresh_character(t_data *data)
{
	ft_draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->character_texture.img, data->map->player.p_pos.x * 100, data->map->player.p_pos.y * 100);
}

int ft_move_player(int key, t_data *data)
{
	if (key == 100 && data->map->map[data->map->player.p_pos.y][data->map->player.p_pos.x + 1] != '1')
		data->map->player.p_pos.x += 1;
	if (key == 97 && data->map->map[data->map->player.p_pos.y][data->map->player.p_pos.x - 1] != '1')
		data->map->player.p_pos.x -= 1;
	if (key == 115 && data->map->map[data->map->player.p_pos.y + 1][data->map->player.p_pos.x] != '1')
		data->map->player.p_pos.y += 1;
	if (key == 119 && data->map->map[data->map->player.p_pos.y - 1][data->map->player.p_pos.x] != '1')
		data->map->player.p_pos.y -= 1;
	if (key == XK_Escape)
		close_redx(data);
	if (data->character_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->character_texture.img);
	ft_refresh_character(data);
	ft_take(data->map->map, data);
	return SUCCESS;

}

int loop(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, &press_keyboard, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, &release_keyboard, data);
	mlx_key_hook(data->win_ptr, *ft_move_player, data);
    mlx_hook(data->win_ptr, 17, 0L, &close_redx, data);
	mlx_loop(data->mlx_ptr);
	return (SUCCESS);
}

int main(int argc, char **argv, char **env)
{
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
	ft_draw(data);
	loop(data);		
    return (SUCCESS);
}