/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:52 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/05 13:33:05 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct flag_t
{
	va_list	*arg;
	char	arg_t;
	int		ret;
	int 	d;
	char	*flag;
	int		zero;
	int		less;
	int		precision;
	int		dot;
	int		star;
	int 	width;
} 				flag_t;

# define ERROR ft_putstr("ERROR\n", check_val);
# define TEST tester('!');

int					ft_printf(const char *format, ...);
int					ft_check_flag(char c);
int					ft_check_args(char c);
void				ft_valneg(flag_t *check_val);
void				init_flag_t(flag_t *check_flag);
void    			ft_parsing(const char *format, flag_t *check_val);
void     			ft_parsingargs(const char *format, int i, flag_t *check_val);
void				ft_parsingflags(flag_t *check_val);
void    			ft_verify_width(flag_t *check_val);
void				ft_verify_precision(flag_t *check_val);
char				*ft_convert_maj(unsigned int num, int base);
char				*ft_convert_min(unsigned int num, int base);
char  				*ft_convert_u(int nb, int base);
char 				*ft_convert_uneg(int num);
char  				*ft_convert_p(unsigned long long nb, int base);
int					ft_convlen(unsigned int num);
char				*ft_reverse(char *str, unsigned long long num);
int					ft_flag_size(const char *format);
void				ft_printcontrol(const char *format, va_list arg, flag_t *check_val);
void				ft_print_percent(flag_t *check_val);
void				ft_printargs(const char *format, int i, flag_t *check_val);
void				ft_print_d(flag_t *check_val);
void    			ft_print_dw(flag_t *check_val);
void    			ft_print_dp(flag_t *check_val);
void    			ft_print_dwp(flag_t *check_val);
void    			ft_print_dd(flag_t *check_val);


#endif