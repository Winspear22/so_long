# include "so_long.h"

int	check_directory(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
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