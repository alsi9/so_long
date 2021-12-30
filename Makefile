# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ephantom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 17:43:42 by ephantom          #+#    #+#              #
#   Updated: 2021/12/25 19:08:11 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS_L	=	check_map.c ft_check_char.c get_next_line.c utils.c

SRCS_A	=	main.c ft_key_hook.c

SRCS_B	=	main_bonus.c  ft_key_hook_bonus.c ft_itoa_bonus.c animation_bonus.c enemy_bonus.c

OBJS_L	=	${SRCS_L:%.c=%.o}

OBJS_A	=	${SRCS_A:%.c=%.o}

OBJS_B	=	${SRCS_B:%.c=%.o}

HEADER	=	so_long.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

RM		=	 rm -f

.PHONY:		all clean fclean re bonus

all:		${NAME}

%.o: 		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS_A} ${OBJS_L} ${HEADER}
			${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS_A} ${OBJS_L}

bonus:
			@make OBJS_A="$(OBJS_B)" all

clean:
			${RM} ${OBJS_A} ${OBJS_B} ${OBJS_L}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
