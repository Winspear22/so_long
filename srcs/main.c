/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:59:14 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/04 16:51:18 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"

void	ft_draw(char **tab, void *mlx, void *window)
{
	t_check_map	map;

	map.i = -1;
	map.j = -1;
	map.k = 0;
	map.l = 0;
	while (tab[++map.i] != '\0')
	{
		while (tab[map.i][++map.j] != '\0')
		{
			if (tab[map.i][map.j] == '1')
				map.k = ft_draw_walls(mlx, window, map.k, map.l);
			else if (tab[map.i][map.j] == '0')
				map.k = map.k + 100;
			if (tab[map.i][map.j] == 'C')
				map.k = ft_draw_items(mlx, window, map.k, map.l);
			if (tab[map.i][map.j] == 'E')
				map.k = ft_draw_exit(mlx, window, map.k, map.l);
			else if (tab[map.i][map.j] == 'P')
				map.k = map.k + 100;
		}
		map.j = -1;
		map.l = map.l + 100;
		map.k = 0;
	}
}

void	ft_init_pgm(t_program pgm)
{
	pgm.mlx = mlx_init();
	pgm.w.ref = NULL;
	pgm.w.size.x = 0;
	pgm.w.size.y = 0;
	pgm.sprite.ref = NULL;
	pgm.sprite.size.x = 0;
	pgm.sprite.size.y = 0;
	pgm.sprite.pixels = NULL;
	pgm.sprite.bits_per_pixel = 0;
	pgm.sprite.line_size = 0;
	pgm.sprite.endian = 0;
}

void	ft_init_img(t_image img)
{
	img.ref = NULL;
	img.size.x = 0;
	img.size.y = 0;
	img.pixels = NULL;
	img.bits_per_pixel = 0;
	img.line_size = 0;
	img.endian = 0;
}

int	ft_quit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	pgm;
	t_image		img;
	t_vector	size_map;
	char		**tab;
	void		*param;

	ft_init_pgm(pgm);
	ft_init_img(img);
	param = NULL;
	tab = NULL;
	if (argc == 2)
	{
		if (ft_check_name(argv[1], ".ber") == 1)
		{
			pgm.mlx = mlx_init();
			size_map = read_map(argv[1], size_map, tab);
			pgm.w = n_window(pgm.mlx,
					size_map.x, size_map.y, "So_long");
		//	check_map(tab, size_map);
			ft_create_background(pgm.mlx, pgm.w.ref, "sprites/namek.xpm", pgm);
			ft_draw(tab, pgm.mlx, pgm.w.ref);
			ft_create_character(pgm.mlx, pgm.w.ref, "sprites/gokuu.xpm", pgm, tab);
			mlx_hook(pgm.w.ref, 17, 0, ft_quit, param);
			mlx_loop(pgm.mlx);
		}
	}
	else
		printf("Error.\nIl y'a trop ou pas assez d'arguments.\n");
	return (0);
}
