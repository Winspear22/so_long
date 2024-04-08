# include "so_long.h"

int	return_failure(char *error_str)
{
	ft_printf("%s%s%s\n", RED, error_str, RESET);
	return (FAILURE);
}
