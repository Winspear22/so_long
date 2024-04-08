# include "so_long.h"

int	parse(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}