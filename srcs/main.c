
# include "so_long.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    if (!(*env))
		return (return_failure("Error. No environment."));
    if (check_arguments(argc, argv[1]) == FAILURE)
		return (FAILURE);
    ft_printf("%s%s%s", GREEN, "réussite", RESET);
    return (SUCCESS);
}