/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:44 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/03 22:24:36 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

t_window	n_window(void	*mlx, int width, int height, char *name)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;
	return (window);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ref,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	ft_create_character(char *path, t_program character, char **tab)
{
	t_vector	player;

	player = ft_player_pos(tab);
	character.sprite = ft_new_sprite(character.mlx, path);
	character.pos.x = player.x * 100;
	character.pos.y = player.y * 100;
	mlx_put_image_to_window(character.mlx, character.w.ref,
		character.sprite.ref, character.pos.x,
		character.pos.y);
}

void	ft_create_background(char *path, t_program map)
{
	 map.sprite = ft_new_sprite(map.mlx, path);
	 mlx_put_image_to_window(map.mlx, map.w.ref, map.sprite.ref, 0, 0);
}
