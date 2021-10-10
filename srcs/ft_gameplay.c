/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:36:51 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/03 22:04:02 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_items(char **tab)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	j = 0;
	items = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				items += 1;
			j++;
		}
		i++;
	}
	return (items);
}

t_vector	ft_player_pos(char **tab)
{
	int			i;
	int			j;
	t_vector	player_pos;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				player_pos.x = j;
				player_pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

void	ft_init_check(t_check_map **m)
{
	*m = malloc(sizeof(t_check_map) * 2);
	if (!m)
		return ;
	(*m)->exit = 0;
        (*m)->senzu = 0;
	(*m)->player = 0;
	(*m)->i = 0;
	(*m)->j = 0;
	(*m)->k = 0;
	(*m)->l = 0;
}