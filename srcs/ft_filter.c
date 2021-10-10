/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:17:04 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/04 17:15:48 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_name(char *str, char *ber)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	while (str[i + j] && ber[j])
	{
		if (ft_toupper(str[i + j]) == ft_toupper(ber[j]))
			j++;
		else
			break ;
	}
	if (ber[j] == '\0' && str[i + j] == '\0')
		return (1);
	write(1, "Error.\nThe file format is not .ber.\n", 38);
	return (0);
}

int	ft_check_map_updown(char **tab, t_vector size_map)
{
	int	i;
	int	j;
	int	max_y;

	i = 0;
	j = 0;
	max_y = size_map.y / 100;
	while (tab && tab[i])
	{
		while (tab[i][j])
		{
			if ((tab[0][j] != '1') || (tab[max_y - 1][j] != '1'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_map_leftright(char **tab, t_vector size_map)
{
	int	i;
	int	j;
	int	max_x;

	i = 0;
	j = 0;
	max_x = size_map.x / 100;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][0] != '1')
				return (0);
			else if (tab[i][max_x - 1] != '1')
				return (0);
			else if (tab[i][j] != '1' && tab[i][j] != '0' &&
				tab[i][j] != 'P' && tab[i][j] != 'C' &&
				tab[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map_elements(char **tab)
{
	t_check_map		*m;

	ft_init_check(&m);
	while (tab && tab[m->i])
	{
		m->j = 0;
		while (tab[m->i] && tab[m->i][m->j])
		{
			if (tab[m->i][m->j] == 'P')
				m->player += 1;
			else if (tab[m->i][m->j] == 'C')
				m->senzu = 1;
			else if (tab[m->i][m->j] == 'E')
				m->exit = 1;
			m->j++;
		}
		m->i++;
	}
	if (m->player == 1 && m->exit == 1 && m->senzu == 1)
	{
		free(m);
		return (1);
	}
	free(m);
	return (0);
}

int	check_map(char **tab, t_vector size_map)
{
	int	check_one;
	int	check_two;
	int	check_three;

	check_one = ft_check_map_updown(tab, size_map);
	check_two = ft_check_map_leftright(tab, size_map);
	check_three = ft_check_map_elements(tab);
	if (check_one == 0 || check_two == 0)
	{
		write(1, "Error.\nMap is not surrounded by walls.\n", 40);
		write(1, "Or there are forbidden characters.\n", 35);
		exit(0);
	}
	if (check_three == 0)
	{
		write(1, "Error.\nInvalid file.\n", 22);
		write(1, "Not enough or too much P, C, E.\n", 33);
		write(1, "Or the file is actually a directory.\n", 38);
		exit(0);
	}
	return (1);
}
