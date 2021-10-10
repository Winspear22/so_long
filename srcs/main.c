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
	while (tab[++map.i])
	{
		while (tab[map.i][++map.j])
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

/*void	ft_init_pgm(t_program pgm, t_vector size_map, char *file)
{
	pgm.mlx = mlx_init();
	pgm.tab = get_map(file);
	size_map = read_map(file, pgm.tab);
	pgm.w.ref = NULL;
	pgm.w = n_window(pgm.mlx,
			size_map.x, size_map.y, "So_long");
	pgm.sprite.size.x = 0;
	pgm.sprite.size.y = 0;
	pgm.sprite.pixels = NULL;
	pgm.sprite.bits_per_pixel = 0;
	pgm.sprite.line_size = 0;
	pgm.sprite.endian = 0;
}*/


int	ft_quit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	ft_create_game(t_program pgm)
{
	ft_create_background("sprites/namek.xpm", pgm);
	ft_draw(pgm.tab, pgm.mlx, pgm.w.ref);
	ft_create_character("sprites/gokuu.xpm", pgm, pgm.tab);
}

int	main(int argc, char **argv)
{
	t_program	pgm;
	t_vector	size_map;
	void		*param;

	param = NULL;
	if (argc == 2 && ft_check_name(argv[1], ".ber") == 1)
	{
			pgm.mlx = mlx_init();
			pgm.tab = get_map(argv[1]);
			size_map = read_map(argv[1], pgm.tab);
			pgm.w = n_window(pgm.mlx,
			size_map.x, size_map.y, "So_long");
			check_map(pgm.tab, size_map);
			pgm.pos = ft_player_pos(pgm.tab);
			pgm.sprite.size = pgm.pos;
			ft_create_game(pgm);
			mlx_key_hook(pgm.w.ref, *ft_move_player, &pgm);
			mlx_hook(pgm.w.ref, 17, 0, ft_quit, param);
			mlx_loop(pgm.mlx);
	}
	else
		write(1, "Error.\nThere's too much or not enough arguments\n", 50);
	return (0);
}
