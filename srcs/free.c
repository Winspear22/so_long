# include "so_long.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_struct(t_map *map)
{
	if (map->map)
		free_tab(map->map);
	free(map);
}

void	free_loading_txt_failed(t_data *data, char **s_byspace)
{
	free_tab(s_byspace);
	if (data->map)
		free_struct(data->map);
	if (data->walls_texture.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->walls_texture.img);
	if (data->floor_texture.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->floor_texture.img);
	if (data->collectible_texture.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->collectible_texture.img);
	if (data->exit_texture.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->exit_texture.img);
	if (data->character_texture.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->character_texture.img);
	if (data->screen.status == 1)
		mlx_destroy_image(data->mlx_ptr, data->screen.img);
	if (data->win_ptr)
	{
		if (data->screen.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->screen.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		data->win_ptr = NULL;
	}
	free(data->mlx_ptr);
	if (data)
		free(data);
	exit (0);
}

void	free_data(t_data *data)
{
    if (data->walls_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->walls_texture.img);
	if (data->floor_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->floor_texture.img);
	if (data->character_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->character_texture.img);
	if (data->exit_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->exit_texture.img);
    if (data->collectible_texture.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->collectible_texture.img);
	if (data->screen.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->screen.img);
    if (data->map)
        free_struct(data->map);
}