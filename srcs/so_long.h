/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:54:21 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/03 22:00:34 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

# define ANIMATION_FRAMES 15
# define BUFFER_SIZE 10000

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window
{
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program
{
	void		*mlx;
	t_window	w;
	t_image		sprite;
	t_vector	pos;
	char		**tab;
}				t_program;

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

void	ft_init_check(t_check_map **m);
char	*join(const char *s1, const char *s2);
t_image		ft_new_sprite(void *mlx, char *path);
t_window	n_window(void *mlx, int width, int height, char *name);
int			ft_sprite_move(void *param);
int			ft_move_player(int key, void *param);
t_vector	read_map(char *argv, char **tab);
char		*ft_get_line(char *s);
char		*ft_get_char(char *s);
int			ft_read(int fd, char **line);
char		*ft_malloc(char *buf);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			get_next_line(int fd, char **line);
char		**ft_split(const char *s, char c);
char 		**get_map(char *argv);
t_vector	map_size(char **full_map, t_vector size);
void		ft_create_character(char *path, t_program character, char **tab);
void		ft_create_background(char *path, t_program map);
void		ft_draw(char **tab, void *mlx, void *window);
int			ft_check_name(char *str, char *ber);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_check_map_updown(char **tab, t_vector size_map);
int			ft_check_map_leftright(char **tab, t_vector size_map);
int			check_map(char **tab, t_vector size_map);
void		ft_loop_image(t_program program, char **tab);
int			ft_count_items(char **tab);
void		ft_take(char **tab, t_program i);
t_vector	ft_player_pos(char **tab);
void		ft_count_movements(t_program i, int key, char **tab);
int			ft_quit(void *param);
int			ft_toupper(int i);
int			ft_draw_walls(void *mlx, void *window, int k, int l);
int			ft_draw_items(void *mlx, void *window, int k, int l);
int			ft_draw_exit(void *mlx, void *window, int k, int l);
void		ft_initialize(t_check_map map);
char		**ft_split(char const *s, char c);
int			ft_toupper(int c);
char		*ft_itoa(int i);
void		ft_init_pgm(t_program *pgm);


#endif
