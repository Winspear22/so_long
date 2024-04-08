# include "so_long.h"

int	check_directory(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_file_existence(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	check_extension(char *argv)
{
	int		i;
	char	*format;

	i = 0;
	format = "ber";
	if (argv[5] == '.' || argv[0] == '.')
		return (FAILURE);
	if (parse(argv) == FAILURE)
		return (1);
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			i++;
			if (ft_strcmp((argv + i), format) != 0)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int is_executable(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == FAILURE)
        return FAILURE;
    // Lire les métadonnées du fichier
    char mode;
	mode = 0;
    if (read(fd, &mode, sizeof(mode)) == FAILURE)
    {
        close(fd);
        return FAILURE;
    }
    close(fd);
    // Vérifier si le bit d'exécution est défini dans les permissions du fichier
    if (mode & S_IXUSR)
        return FAILURE; // Le fichier est un exécutable
    return SUCCESS; // Le fichier n'est pas un exécutable
}


int	check_arguments(int argc, char *argv)
{
	(void)argc;
	(void)argv;
	int	ret;

	ret = 0;
	if (argc != 2)
		return (return_failure("Error. Wrong number of arguments."));
	ret = check_directory(argv);
	if (ret == FAILURE)
		return (return_failure("Error. You are trying to open a directory."));
	ret = is_executable(argv);
	if (ret == FAILURE)
		return (return_failure("Error. You are trying to open an executable."));
	ret = check_file_existence(argv);
	if (ret == FAILURE)
		return (return_failure("Error. No file existing or no permission."));
	ret = check_extension(argv);
	if (ret == FAILURE)
		return (return_failure("Error. Extension map invalid."));
	if (ret == 1)
		return (return_failure("Error. Extension file missing."));
	return (SUCCESS);
}