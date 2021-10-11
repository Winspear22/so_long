/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:00 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/11 14:21:01 by adaloui          ###   ########.fr       */
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

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	join = len_s1 + len_s2;
	str = (char *)malloc(sizeof(char *) * (join + 2));
	if (str == NULL)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[join] = '\n';
	str[join + 1] = '\0';
	return (str);
}

char	**get_map(char *file)
{
	char			*buffer;
	char			*map;
	char			**full_map;
	int				fd;

	map = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error.\nCannot open file.\n");
		exit(0);
	}
	while (get_next_line(fd, &buffer) > 0)
	{
		map = join(map, buffer);
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
	if (full_map == NULL)
	{
		printf("Error.\nFile empty or is a repository\n");
		exit (0);
	}
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

t_vector	read_map(char *file, char **tab)
{
	int				fd;
	t_vector		map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error.\nCannot open file.\n");
		exit(0);
	}
	tab = get_map(file);
	map = map_size(tab, map);
	close(fd);
	return (map);
}
