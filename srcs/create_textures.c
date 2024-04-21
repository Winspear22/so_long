# include "so_long.h"

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