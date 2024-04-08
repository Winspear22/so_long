# include "so_long.h"

int	return_failure(char *error_str)
{
	ft_printf("%s%s%s\n", RED, error_str, RESET);
	return (FAILURE);
}

int	ret_free(char *error_str, char **tab)
{
	if (error_str != NULL)
		printf("\033[1;31m%s\n\033[0m", error_str);
	free_tab(tab);
	return (FAILURE);
}