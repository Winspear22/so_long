/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:10:18 by adaloui           #+#    #+#             */
/*   Updated: 2021/09/21 16:12:05 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	join;

	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	join = len_s1 + len_s2 + 1;
	if (!s1 && !s2)
		return (0);
	str = (char *)malloc(sizeof(char *) * (join));
	if (str == NULL)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[join - 1] = '\0';
	free((char *)s1);
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s2;
	char		*s1;
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		s1 = d + (len - 1);
		s2 = s + (len - 1);
		while (len--)
			*s1-- = *s2--;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
