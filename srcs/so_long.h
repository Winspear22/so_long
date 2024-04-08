#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <unistd.h>

# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"


# define SUCCESS	0
# define FAILURE	-1

# define RESET		"\033[0m"
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

/* =================================================== */
/* ---------------------STRUCTURES---------------------*/
/* =================================================== */

/*typedef struct 	s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}				t_data;*/

/* =================================================== */


/* =================================================== */
/* -----------------------ERRORS.C---------------------*/
/* =================================================== */

int	return_failure(char *error_str);

/* =================================================== */


/* =================================================== */
/* -----------------FIRST_STEP_PARSE-------------------*/
/* =================================================== */

int	check_directory(char *av);
int	check_file_existence(char *av);
int	check_extension(char *av);
int check_arguments(int argc, char *argv);

/* =================================================== */

/* =================================================== */
/* -----------------------UTILS.C-(--------------------*/
/* =================================================== */

int	parse(char *argv);

#endif