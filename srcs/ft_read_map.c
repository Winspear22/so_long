/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:00 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/04 17:11:44 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <string.h>

char	*join(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	join;

	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	join = len_s1 + len_s2;
	if (!s1 && !s2)
		return (0);
	str = (char *)malloc(sizeof(char *) * (join + 2));
	if (str == NULL)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[join] = '\n';
	str[join + 1] = '\0';
	return (str);
}

char	**get_map(int fd, t_vector size)
{
	char			*buffer;
	char			*map;
	char			**full_map;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (size.x == 9999 && size.y == 9999)
		;
	while (get_next_line(fd, &buffer) > 0)
	{
		map = join(map, buffer);
		i = ft_strlen(map);
		if (i <= 0)
			return (0);
		free(buffer);
	}
	full_map = ft_split(map, '\n');
	return (full_map);
}

t_vector	map_size(char **full_map, t_vector size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	size.x = 0;
	size.y = 0;
	while (full_map[i])
	{
		while (full_map[i][j])
			j++;
		i++;
	}
	size.y = i * 100;
	size.x = j * 100;
	return (size);
}

t_vector	read_map(char *file, t_vector size, char **tab)
{
	int				fd;
//	char			*buffer;
//	char			*map_draw;
//	char			**full_map;
//	int				i;
//	int				j;
	t_vector		map;

//	i = 0;
//	j = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error.\nOuverture du fichier impossible.\n");
		exit(0);
	}
/*	while (get_next_line(fd, &buffer) > 0)
	{
		map_draw = join(map_draw, buffer);
		i = ft_strlen(map_draw);
		if (i <= 0)
			return (0);
		free(buffer);
	}
	full_map = ft_split(map_draw, '\n');
	map.x = 0;
	map.y = 0;
	while (full_map[i])
	{
		while (full_map[i][j])
			j++;
		i++;
	}
	size.y = i * 100;
	size.x = j * 100;*/
	tab = get_map(fd, size);
	map = map_size(tab, size);
	close(fd);
	return (map);
}
