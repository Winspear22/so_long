# include "get_next_line.h"

static int	ft_search_n(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_get_line(char *save)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	len = i + 1;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && i < len)
	{
		cpy[i] = save[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_after_n(char *save)
{
	unsigned int	i;
	char			*cpy;
	char			*tmp;

	tmp = ft_strchr_2(save, '\n');
	i = ft_strlen_2(tmp);
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		cpy[i] = tmp[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_return(char **save, char **line, int ret)
{
	if (ret == 0 && **line == '\0')
	{	
		free(*line);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*save;
	char		*line;
	char		*tmp;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	if (save == 0)
		save = ft_strdup_2("\0");
	while (ft_search_n(save) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		save = ft_strjoin_2(save, buf);
	}
	line = ft_get_line(save);
	tmp = ft_after_n(save);
	free(save);
	save = ft_strdup_2(tmp);
	free(tmp);
	return (ft_return(&save, &line, ret));
}