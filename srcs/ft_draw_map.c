/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:49:12 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/02 00:37:24 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_walls(void *mlx, void *window, int k, int l)
{
	t_program	walls;

	walls.sprite = ft_new_sprite(mlx, "sprites/wallhd.xpm");
	mlx_put_image_to_window(mlx, window, walls.sprite.ref, k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_items(void *mlx, void *window, int k, int l)
{
	t_program	walls;

	walls.sprite = ft_new_sprite(mlx, "sprites/senzu.xpm");
	mlx_put_image_to_window(mlx, window, walls.sprite.ref, k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_exit(void *mlx, void *window, int k, int l)
{
	t_program	walls;

	walls.sprite = ft_new_sprite(mlx, "sprites/freezer.xpm");
	mlx_put_image_to_window(mlx, window, walls.sprite.ref, k, l);
	k = k + 100;
	return (k);
}

int	ft_draw_grass(void *mlx, void *window, int k, int l)
{	
	t_program	walls;

	walls.sprite = ft_new_sprite(mlx, "sprites/grass.xpm");
	mlx_put_image_to_window(mlx, window, walls.sprite.ref, k, l);
	k = k + 100;
	return (k);
	
}