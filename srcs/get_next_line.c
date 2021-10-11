/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:10:06 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/03 19:08:18 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_get_char(char *s)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	if (!s[len])
	{
		free(s);
		return (0);
	}
	ret = (char *)malloc(sizeof(char) * ((ft_strlen(s) - len)) + 1);
	if (ret == 0)
		return (0);
	len++;
	while (s[len] != '\0')
		ret[i++] = s[len++];
	ret[i] = '\0';
	free(s);
	return (ret);
}

char	*ft_get_line(char *s)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_read(int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	return (1);
}

char	*ft_malloc(char *buf)
{
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buf == NULL)
		return (NULL);
	return (buf);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			i;

	i = 1;
	buf = NULL;
	ft_read(fd, line);
	buf = ft_malloc(buf);
	while (!ft_strchr(str) && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	*line = ft_get_line(str);
	str = ft_get_char(str);
	if (i == 0)
		return (0);
	return (1);
}
