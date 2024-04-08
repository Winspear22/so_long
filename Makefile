# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaloui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 16:24:38 by adaloui           #+#    #+#              #
#    Updated: 2021/10/04 17:18:57 by adaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=/usr/include
INCLIB=/usr/include/X11

SRCS =	./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c \
		./srcs/errors.c \
		./srcs/first_step_parse.c \
		./srcs/utils.c \
		./srcs/main.c \

OBJS	= ${SRCS:.c=.o}

UNAME	:= $(shell uname)

PATH_MLX	= minilibx-linux
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3 -I$(INC) -I$(INCLIB)
RM			= rm -f
NAME		= so_long
FLAGS		= -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -Iminilibx-linux minilibx-linux/libmlx.a

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_PATH = ft_printf
LIBFTPRINTF_MAKE = $(LIBFTPRINTF_PATH)/Makefile
LIBFTPRINTF_MAKE_COMMAND = $(MAKE) -C $(LIBFTPRINTF_PATH)

LIBFT_PATH = ft_printf/libft
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_INC = -I$(LIBFT_PATH)

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass $(LIBFT_INC) -c $< -o ${<:.c=.o}

$(LIBFTPRINTF):
	$(LIBFTPRINTF_MAKE_COMMAND)

$(NAME):	$(LIBFTPRINTF) $(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) -L$(LIBFT_PATH) -lft -L$(LIBFTPRINTF_PATH) -lftprintf

clean:
			make -C $(PATH_MLX) clean
			$(RM) $(OBJS)
			$(RM) $(NAME)
			$(LIBFTPRINTF_MAKE_COMMAND) clean

fclean: 	clean
			make -C $(PATH_MLX) clean
			$(RM) ${NAME}
			$(RM) $(LIBFTPRINTF)
			$(LIBFTPRINTF_MAKE_COMMAND) fclean

re: 		fclean all

silent_make:
			make --no-print-directory -s | pv -l >/dev/null

silent_fclean:
			make --no-print-directory -s fclean | pv -l >/dev/null

.PHONY:		all clean fclean re silent_make silent_fclean
