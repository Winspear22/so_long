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

#INCLIB=$(INC)/../lib 
INCLIB=/usr/include/X11


SRCS =	./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c \
		./srcs/main.c \

OBJS	= ${SRCS:.c=.o}

UNAME	:= $(shell uname)

PATH_MLX	= minilibx-linux
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror  
RM			= rm -f
NAME		= so_long
FLAGS		= -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -Iminilibx-linux minilibx-linux/libmlx.a

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			$(RM) $(OBJS)
			$(RM) $(NAME)

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
