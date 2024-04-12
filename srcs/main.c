
# include "so_long.h"

int loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->walls_texture.img, 0, 0);
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
	if (create_textures_wall(data) == FAILURE)
		return (FAILURE);
    ft_printf("%s%s%s", GREEN, "réussite", RESET);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->screen.img, 0, 0);
	mlx_loop_hook(data->mlx_ptr, loop, data);
	//loop(data);
	mlx_loop(data->mlx_ptr);
    return (SUCCESS);
}