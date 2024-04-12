# include "so_long.h"

int	put_new_image_on_screen(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	if (!data->screen.img)
		return (return_failure("Error\nInit display\n"));
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bpp,
			&data->screen.line, &data->screen.endian);
	if (!data->screen.addr)
		return (return_failure("Error\nInit display\n"));
    printf("%s\n", "JE SUIS ICI");
	return (SUCCESS);
}

int	init_window(t_data *data)
{
	data->win_width = data->map->map_max_size.x;
	data->win_height = data->map->map_max_size.y;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		free(data);
		return (FAILURE);
	}
	if (put_new_image_on_screen(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}