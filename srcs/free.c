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
	/*if (map->map_max_size.x && map->map_max_size.y)
	{
		free(map->map_max_size.x);
		free(map->map_max_size.y);
	}*/
	free(map);
	printf("%s%ld\n", "size of map 4 = ", sizeof(map));

}

void	free_data(t_data *data)
{
	/*if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img != NULL)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->north.img != NULL)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->screen.img != NULL)
		mlx_destroy_image(data->mlx, data->screen.img);*/
//	if (data->map)
//		free_struct(data->map);
    if (data->map)
        free_struct(data->map);
}