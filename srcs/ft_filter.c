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
	printf("Error.\nLe format du fichier n'est pas .ber.\n");
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
	while (tab[i])
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
	while (tab[i])
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
	int			i;
	int			j;
	t_check_map	m;

	i = 0;
	j = 0;
	m.player = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				m.player += 1;
			else if (tab[i][j] == 'C')
				m.senzu = 1;
			else if (tab[i][j] == 'E')
				m.exit = 1;
			j++;
		}
		i++;
	}
	if (m.player == 1 && m.exit == 1 && m.senzu == 1)
		return (1);
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
		printf("Error.\nLa carte n'est pas entouree par des murs.\n");
		printf("Ou il y'a un caractere interdit.\n");
		exit(0);
	}
	if (check_three == 0)
	{
		printf("Error.\nLe fichier n'est pas valide.\n");
		printf("Trop ou pas assez de P, C, E.\n");
		printf("Ou le fichier est un dossier.\n");
		exit(0);
	}
	return (1);
}
