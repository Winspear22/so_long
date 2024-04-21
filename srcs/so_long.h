#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
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

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_gameplay
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			look_left;
	int			look_right;
	int			escape;
}				t_gameplay;

typedef struct	s_player
{
	t_vector	p_pos;
	t_gameplay	gamplay;
}				t_player;

typedef struct s_check
{
	int			exit;
	int			senzu;
	int			player;
	int			i;
	int			j;
	int			k;
	int			l;
}				t_check_map;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			height;
	int			width;
	int			endian;
	int			line;
	int			status;
}				t_img;


typedef struct	s_verif
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
	t_vector	map_max_size;
	t_player	player;
	int			player_switch;
	int			senzu_switch;
}				t_map;

typedef struct 	s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	int			win_height;
	int			win_width;
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
	
	t_img		screen;
	t_img		walls_texture;
	t_img		collectible_texture;
	t_img		floor_texture;
	t_img		exit_texture;
	t_img		character_texture;
}				t_data;

/* =================================================== */


/* =================================================== */
/* -----------------------ERRORS.C---------------------*/
/* =================================================== */

int			return_failure(char *error_str);
int			ret_free(char *error_str, char **tab);
int			ret_free_txt(char *error_str, t_data *data);

/* =================================================== */

/* =================================================== */
/* ------------------------FREE.C----------------------*/
/* =================================================== */

void		free_tab(char **str);
void		free_loading_txt_failed(t_data *data);
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
t_map		*reduce_get_map(t_data *data, int fd);
t_map		*get_map(char *s, t_data *data);

/* =================================================== */

/* =================================================== */
/* -----------------CHECK_LINE_CONTENT.C---------------*/
/* =================================================== */

int			check_map_content(t_map *map);

/* =================================================== */


/* =================================================== */
/* -----------------------UTILS.C----------------------*/
/* =================================================== */

int			parse(char *argv);
char		*strdup_no_n(const char *s1);

/* =================================================== */
/*------------------------WINDOW.C---------------------*/
/* =================================================== */

int			put_new_image_on_screen(t_data *data);
int			init_window(t_data *data);

/* =================================================== */
/*------------------------WINDOW.C---------------------*/
/* =================================================== */

int	get_xpm_to_img(t_data *data, char **s, char *texture, t_img *txt);
int	reduce_create_textures_wall(t_data *data, char *s);
int create_textures_wall(t_data *data);

#endif