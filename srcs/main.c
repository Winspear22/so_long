
# include "so_long.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    if (!(*env))
		return (return_failure("Error\nNo environment."));
    ft_printf("%s", "réussite\n");
    return (SUCCESS);
}