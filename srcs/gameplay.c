# include "so_long.h"

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
