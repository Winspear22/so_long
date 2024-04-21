
# include "so_long.h"

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