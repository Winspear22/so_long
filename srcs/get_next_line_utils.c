# include "get_next_line.h"

int	ft_strlen_2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_2(const char *s)
{
	char	*cpy;
	int		len;

	len = ft_strlen_2(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	len = 0;
	while (s[len])
	{
		cpy[len] = s[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

void	*ft_memmove_2(char *save, char *buf, int n)
{
	char	tmp;
	int		i;

	i = 0;
	if (!save && !buf)
		return (NULL);
	if (save > buf)
	{
		while (n > 0)
		{
			tmp = buf[n - 1];
			save[n - 1] = tmp;
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			save[i] = buf[i];
			i++;
		}
	}
	return (save);
}

char	*ft_strjoin_2(char *save, char *buf)
{
	char	*cpy;
	int		len;

	if (!save && !buf)
		return (NULL);
	len = ft_strlen_2(save) + ft_strlen_2(buf);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_memmove_2(cpy, save, ft_strlen_2(save));
	ft_memmove_2(cpy + ft_strlen_2(save), buf, ft_strlen_2(buf));
	cpy[len] = '\0';
	free(save);
	return (cpy);
}

char	*ft_strchr_2(char *save, int c)
{
	while (*save != '\0' && *save != (char)c)
		save++;
	if (*save == (char)c && *save != '\0')
		return (save + 1);
	else if (*save == '\0')
		return (save);
	return (NULL);
}
