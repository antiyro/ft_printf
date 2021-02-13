/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:52 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/14 14:05:49 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include "../../include/ft_printf.h"

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_nbrlen(int n);
size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(char *nbr);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2,
	t_struc *check_val);
char				*ft_itoa(long long n);
void				ft_putchar(char c, t_struc *check_val);
void				ft_putstr(char *s, t_struc *check_val);
void				ft_putnbr(int n, t_struc *check_val);

#endif
