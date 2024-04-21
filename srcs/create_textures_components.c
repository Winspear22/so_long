# include "so_long.h"

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