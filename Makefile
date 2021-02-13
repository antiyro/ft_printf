# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:43:21 by nbouhada          #+#    #+#              #
#    Updated: 2020/11/23 15:43:32 by nbouhada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS_LIST	= ft_tools.c ft_printf.c ft_verify.c ft_tools2.c ft_apply.c ft_print_d.c\
				ft_print_c.c ft_print_u.c ft_print_x.c ft_print_xmaj.c ft_print_perc.c\
				ft_print_s.c ft_print_p.c ft_tools3.c ft_convert.c ft_menu.c ft_menu2.c\

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

OUT				= a.out

HEADER			= includes
FOLDER			= src

LIBFT 			= src/libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp src/libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS} ${OUT} 
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
