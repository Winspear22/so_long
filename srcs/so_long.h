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

typedef struct s_verif
{
	long long	exit;
	long long	player;
	long long	collectible;
}				t_verif;

typedef struct	s_map
{
	char		**map;
	int			fd;
	int			count_line;
}				t_map;

typedef struct 	s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	int			win_height;
	int			win_width;
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}				t_data;

/* =================================================== */


/* =================================================== */
/* -----------------------ERRORS.C---------------------*/
/* =================================================== */

int			return_failure(char *error_str);
int			ret_free(char *error_str, char **tab);

/* =================================================== */

/* =================================================== */
/* ------------------------FREE.C----------------------*/
/* =================================================== */

void		free_tab(char **str);
void		free_struct(t_map *map);
void		free_data(t_data *data);

/* =================================================== */


/* =================================================== */
/* ------------------------INIT.C----------------------*/
/* =================================================== */

int			init_data(t_data *data);
t_verif		verif_init(void);

/* =================================================== */


/* =================================================== */
/* -----------------FIRST_STEP_PARSE.C-----------------*/
/* =================================================== */

int			check_directory(char *av);
int			check_file_existence(char *av);
int			check_extension(char *av);
int			check_arguments(int argc, char *argv);
int			is_executable(const char *filename);

/* =================================================== */


/* =================================================== */
/* ----------------SECOND_STEP_PARSE.C-----------------*/
/* =================================================== */

int			check_file_content(char *argv, t_data *data);

/* =================================================== */

/* =================================================== */
/* ------------------GET_MAP_CONTENT.C-----------------*/
/* =================================================== */

int			check_get_next_line(char *line);
t_map		*reduce_count_line(t_data *data, int fd);
t_map		*count_line(char *s, t_data *data);

/* =================================================== */

/* =================================================== */
/* -----------------CHECK_LINE_CONTENT.C---------------*/
/* =================================================== */

int			check_line_content(t_map *map, t_data *data);

/* =================================================== */


/* =================================================== */
/* -----------------------UTILS.C-(--------------------*/
/* =================================================== */

int			parse(char *argv);
char		*strdup_no_n(const char *s1);


#endif