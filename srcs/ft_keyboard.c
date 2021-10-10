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


void	ft_refresh_character(char *path, t_program character, char **tab)
{
	ft_create_background("sprites/namek.xpm", character);
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
		printf("Vous avez reussi le jeu, bravo !\n");
		exit (0);
	}
}

void	ft_count_movements(t_program i, int key, char **tab)
{
	static int move_count;

	if (key == 100 && tab[i.pos.y][i.pos.x + 1] != '1')
		move_count++;
	else if (key == 97 && tab[i.pos.y][i.pos.x - 1] != '1')
		move_count++;
	else if (key == 115 && tab[i.pos.y + 1][i.pos.x] != '1')
		move_count++;
	else if (key == 119 && tab[i.pos.y - 1][i.pos.x] != '1')
		move_count++;
	mlx_string_put(i.mlx, i.w.ref, 50, 50,
                15921105, ft_itoa((int)move_count));
	printf("Le nombre de mouvements est de = %d\n", move_count);
}

int		ft_move_player(int key, void *param)
{
	t_program *i;

	i = (t_program *)param;
	printf("%d\n", key);
 	if (key == 100 && i->tab[i->pos.y][i->pos.x + 1] != '1') //x = +1
	{
		i->pos.x += 1; 
		i->sprite.size.x = i->pos.x;
	}
	else if (key == 97 && i->tab[i->pos.y][i->pos.x - 1] != '1') //x = -1
	{
		i->pos.x -= 1; 
		i->sprite.size.x = i->pos.x;
	}
	else if (key == 115 && i->tab[i->pos.y + 1][i->pos.x] != '1')  //y = +1
	{
		i->pos.y += 1; 
		i->sprite.size.y = i->pos.y;
	}
	else if (key == 119 && i->tab[i->pos.y - 1][i->pos.x] != '1')  //y = -1
	{
		i->pos.y -= 1; 
		i->sprite.size.y = i->pos.y;
	}
	mlx_clear_window(i->mlx, i->w.ref);
	ft_refresh_character("sprites/gokuu.xpm", *i, i->tab);
	ft_count_movements(*i, key, i->tab);
	ft_take(i->tab, *i);
	if (key == 65307)
		exit(0);
	return (0);
}
