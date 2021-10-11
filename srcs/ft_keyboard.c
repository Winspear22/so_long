/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:22:36 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/11 14:19:01 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <stdlib.h>

void	ft_refresh_character(char *path, t_program character)
{
	ft_draw(character.tab, character.mlx, character.w.ref);
	character.sprite = ft_new_sprite(character.mlx, path);
	mlx_put_image_to_window(character.mlx, character.w.ref,
		character.sprite.ref, character.pos.x * 100,
		character.pos.y * 100);
}

void	ft_take(char **tab, t_program pgm)
{
	int	items;

	items = 0;
	items = ft_count_items(tab);
	if (tab[pgm.pos.y][pgm.pos.x] == 'C')
	{
		tab[pgm.pos.y][pgm.pos.x] = '0';
		items -= 1;
	}
	if (tab[pgm.pos.y][pgm.pos.x] == 'E' && items == 0)
	{
		write(1, "You finished the game, congrats !\n", 35);
		exit (0);
	}
}

int	ft_count_movements(t_program i, int key)
{
	static int	move_count;

	if (key == 100 && i.tab[i.pos.y][i.pos.x + 1] != '1')
		move_count++;
	else if (key == 97 && i.tab[i.pos.y][i.pos.x - 1] != '1')
		move_count++;
	else if (key == 115 && i.tab[i.pos.y + 1][i.pos.x] != '1')
		move_count++;
	else if (key == 119 && i.tab[i.pos.y - 1][i.pos.x] != '1')
		move_count++;
	write(1, "The number of mouvements is ", 29);
	printf("%d\n", move_count);
	return ((int)move_count);
}

int	ft_move_player(int key, void *param)
{
	t_program	*i;
	int j;

	i = (t_program *)param;
	j = ft_count_movements(*i, key);
	if (key == 100 && i->tab[i->pos.y][i->pos.x + 1] != '1')
		i->pos.x += 1;
	else if (key == 97 && i->tab[i->pos.y][i->pos.x - 1] != '1')
		i->pos.x -= 1;
	else if (key == 115 && i->tab[i->pos.y + 1][i->pos.x] != '1')
		i->pos.y += 1;
	else if (key == 119 && i->tab[i->pos.y - 1][i->pos.x] != '1')
		i->pos.y -= 1;
	ft_refresh_character("sprites/gokuu.xpm", *i);
	ft_take(i->tab, *i);
	if (key == 65307)
		exit(0);
	mlx_string_put(i->mlx, i->w.ref,
	 50, 50, 15921105, ft_itoa(j));
	return (0);
}
