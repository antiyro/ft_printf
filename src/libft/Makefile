# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:43:21 by nbouhada          #+#    #+#              #
#    Updated: 2021/01/14 14:05:08 by nbouhada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

GCC		= gcc -Wall -Wextra -Werror

SRC		= ft_putstr.c ft_strlen.c ft_putchar.c ft_putnbr.c ft_atoi.c ft_isdigit.c \
		ft_strcat.c ft_strdup.c ft_nbrlen.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_itoa.c ft_tostr.c\

OBJ 	= $(SRC:.c=.o)

INC		= -I includes/

$(NAME): $(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
%.o: %.c
				$(GCC) $(INC) -o $@ -c $?

all: $(NAME)

clean:
				rm -rf $(OBJ)
fclean: clean
				rm -rf $(NAME)
re: fclean all

.PHONY: clean
