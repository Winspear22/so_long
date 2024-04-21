#ifndef SO_LONG_H
# define SO_LONG_H

/* =================================================== */
/* ---------------------LIBRAIRIES-------------------- */
/* =================================================== */

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

/* =================================================== */


/* =================================================== */
/* --------------------DEFINITIONS-------------------- */
/* =================================================== */

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


/* =================================================== */
/* ---------------------STRUCTURES-------------------- */
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
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_height;
	int			win_width;
	t_map		*map;
	t_img		screen;
	t_img		walls_texture;
	t_img		collectible_texture;
	t_img		floor_texture;
	t_img		exit_texture;
	t_img		character_texture;
}				t_data;

/* =================================================== */

/* =================================================== */
/* -----------------CHECK_LINE_CONTENT.C-------------- */
/* =================================================== */

int			check_all_elements(t_map *map, t_verif check);
int			ft_check_wall_map_updown(t_map *map);
int			ft_check_wall_map_leftright(t_map *map);
int			check_map_content(t_map *map);

/* =================================================== */

/* =================================================== */
/*---------------CREATE_TEXTURE_COMPONENTS.C---------- */
/* =================================================== */

int			ft_draw_walls(void *mlx, void *window, int k, int l, t_data *data);
int			ft_draw_grass(void *mlx, void *window, int k, int l, t_data *data);
int			ft_draw_items(void *mlx, void *window, int k, int l, t_data *data);
int			ft_draw_exit(void *mlx, void *window, int k, int l, t_data *data);
int			ft_create_character(void *mlx, void *window, int k, int l, t_data *data);

/* =================================================== */

/* =================================================== */
/*---------------CREATE_TEXTURE_UTILS.C--------------- */
/* =================================================== */

int			ft_count_items(char **tab);
t_vector	ft_player_pos(char **tab);

/* =================================================== */


/* =================================================== */
/*-------------------CREATE_TEXTURES.C---------------- */
/* =================================================== */

t_img		ft_new_sprite(void *mlx, char *path);
int			ft_draw(t_data *data);

/* =================================================== */


/* =================================================== */
/* -----------------------ERRORS.C-------------------- */
/* =================================================== */

int			return_failure(char *error_str);
int			ret_free(char *error_str, char **tab);
int			ret_free_txt(char *error_str, t_data *data);

/* =================================================== */


/* =================================================== */
/* -----------------FIRST_STEP_PARSE.C---------------- */
/* =================================================== */

int			check_directory(char *av);
int			check_file_existence(char *av);
int			check_extension(char *av);
int			is_executable(const char *filename);
int			check_arguments(int argc, char *argv);

/* =================================================== */


/* =================================================== */
/* ------------------------FREE.C--------------------- */
/* =================================================== */

void		free_tab(char **str);
void		free_struct(t_map *map);
void		free_loading_txt_failed(t_data *data);
void		free_data(t_data *data);

/* =================================================== */


/* =================================================== */
/*-----------------------GAMEPLAY.C------------------- */
/* =================================================== */

void		ft_take(char **tab, t_data *data);
void		ft_refresh_character(t_data *data);
int			ft_move_player(int key, t_data *data);
int			press_keyboard(int key, t_data *data);
int			release_keyboard(int key, t_data *data);

/* =================================================== */


/* =================================================== */
/* ------------------GET_MAP_CONTENT.C---------------- */
/* =================================================== */

int			check_get_next_line(char *line);
int			get_number_of_lines(char *s);
t_map		*reduce_get_map(t_data *data, int fd);
t_vector	get_map_size(t_data *data);
t_map		*get_map(char *s, t_data *data);

/* =================================================== */


/* =================================================== */
/* ------------------------INIT.C--------------------- */
/* =================================================== */

t_verif		verif_init(void);
void		init_img(t_data *data);
void		init_floor_walls_texture(t_data *data);
void 		init_collectible_exit(t_data *data);
int			init_data(t_data *data);

/* =================================================== */


/* =================================================== */
/* ----------------SECOND_STEP_PARSE.C---------------- */
/* =================================================== */

int			check_file_content(char *argv, t_data *data);

/* =================================================== */


/* =================================================== */
/* -----------------------UTILS.C--------------------- */
/* =================================================== */

int			parse(char *argv);
char		*strdup_no_n(const char *s1);

/* =================================================== */

/* =================================================== */
/*------------------------WINDOW.C-------------------- */
/* =================================================== */

int			close_redx(t_data *data);
int			put_new_image_on_screen(t_data *data);
int			init_window(t_data *data);

/* =================================================== */

#endif