/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:22:36 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/03 22:41:45 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <stdlib.h>

void	ft_loop_image(t_program program, char **tab)
{
	mlx_put_image_to_window(program.mlx, program.w.ref,
		program.sprite.ref, program.pos.x,
		program.pos.y);
	ft_create_background(program.mlx, program.w.ref,
		"sprites/namek.xpm", program);
	ft_draw(tab, program.mlx, program.w.ref);
//	mlx_string_put(program.mlx, program.w.ref, 50, 50,
//		15921105, ft_itoa((int)g_move_count));
}

void	ft_take(char **tab, t_program pgm)
{
	int	items;

	items = 0;
	items = ft_count_items(tab, items);
	if (tab[pgm.pos.y / 100][pgm.pos.x / 100] == 'C')
	{
		tab[pgm.pos.y / 100][pgm.pos.x / 100] = '0';
		items -= 1;
	}
	if (tab[pgm.pos.y / 100][pgm.pos.x / 100] == 'E' && items == 0)
	{
		printf("Vous avez reussi le jeu, bravo !\n");
		exit (0);
	}
}

/*void	ft_count_movements(t_program i, int key, char **tab)
{

	if (key == 2 && tab[i.pos.y / 100][i.pos.x / 100 + 1] != '1')
		g_move_count++;
	else if (key == 0 && tab[i.pos.y / 100][i.pos.x / 100 - 1] != '1')
		g_move_count++;
	else if (key == 1 && tab[i.pos.y / 100 + 1][i.pos.x / 100] != '1')
		g_move_count++;
	else if (key == 13 && tab[i.pos.y / 100 - 1][i.pos.x / 100] != '1')
		g_move_count++;
	printf("Le nombre de mouvements est de = %d\n", g_move_count);
}*/

char	**naruto(char *file)
{
	int				fd;
	char			*buffer;
	char			*map_draw;
	char			**full_map;
	int				i;
	int				j;
	t_vector		map;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error.\nOuverture du fichier impossible.\n");
		exit(0);
	}
	while (get_next_line(fd, &buffer) > 0)
	{
		map_draw = join(map_draw, buffer);
		i = ft_strlen(map_draw);
		if (i <= 0)
			return (0);
		free(buffer);
	}
	full_map = ft_split(map_draw, '\n');
	return (full_map);
}


int	ft_move_character(int key, void *param, char **argv)
{
	t_program	*i;
	char **tab;

	tab = naruto(argv[1]);

	i = (t_program *)param;
	mlx_clear_window(i->mlx, i->w.ref);
//	ft_count_movements(*i, key, tab);
	if (key == 2 && tab[i->pos.y / 100][i->pos.x / 100 + 1] != '1')
		i->pos.x += i->sprite.size.x;
	else if (key == 0 && tab[i->pos.y / 100][i->pos.x / 100 - 1] != '1')
		i->pos.x -= i->sprite.size.x;
	else if (key == 1 && tab[i->pos.y / 100 + 1][i->pos.x / 100] != '1')
		i->pos.y += i->sprite.size.y;
	else if (key == 13 && tab[i->pos.y / 100 - 1][i->pos.x / 100] != '1')
		i->pos.y -= i->sprite.size.y;
	if (key == 53)
		exit(0);
	ft_loop_image(*i, tab);
	ft_take(tab, *i);
	return (0);
}

int	ft_sprite_move(void *param)
{
	t_program		*program;
	static int		frame;

	program = (t_program *)param;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->pos.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->pos.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->w.ref,
		program->sprite.ref, program->pos.x,
		program->pos.y);
	return (0);
}
