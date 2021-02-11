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

//test git
typedef struct flag_t
{
	va_list	*arg;
	char	arg_t;
	int		ret;
	int 	d;
	int 	c;
	char 	perc;
	char 	*s;
	char	*p;
	char 	*u;
	char 	*x;
	char 	*X;
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

//TOOLS
int					ft_check_flag(char c);
int					ft_check_args(char c);
void				ft_valneg(flag_t *check_val);
void				ft_filltronc(int *tronc, flag_t *check_val);
void				ft_filltroncu(int *tronc, flag_t *check_val);
void				ft_filltroncx(int *tronc, flag_t *check_val);
void				ft_filltroncX(int *tronc, flag_t *check_val);
void				ft_filltroncp(int *tronc, flag_t *check_val);
void				ft_filltroncperc(int *tronc, flag_t *check_val);
void				ft_filltroncstr(int *tronc, flag_t *check_val);
void				init_flag_t(flag_t *check_flag);
char				*ft_convert_X(unsigned int num, int base);
char				*ft_convert_x(unsigned int num, int base);
char  				*ft_convert_u(int nb, int base);
char 				*ft_convert_uneg(int num);
char  				*ft_convert_p(unsigned long long nb, int base);
int					ft_convlen(unsigned int num);
int					ft_convlenp(unsigned long long num);
char				*ft_reverse(char *str, unsigned long long num);
int					ft_flag_size(const char *format);

//PRINTF
int					ft_printf(const char *format, ...);
void    			ft_parsing(const char *format, flag_t *check_val);
void     			ft_parsingargs(const char *format, int i, flag_t *check_val);
void				ft_parsingflags(flag_t *check_val);

//VERIFY
void    			ft_verify_width(flag_t *check_val);
void				ft_verify_precision(flag_t *check_val);
void    			ft_verify_less(flag_t *check_val);

void				ft_printcontrol(const char *format, va_list arg, flag_t *check_val);
void				ft_print_percent(flag_t *check_val);
void				ft_printargs(const char *format, int i, flag_t *check_val);
void				ft_print_d(flag_t *check_val);
void    			ft_print_dw(flag_t *check_val);
void    			ft_print_dp(flag_t *check_val);
void    			ft_print_dwp(flag_t *check_val);
void    			ft_print_dwp2(flag_t *check_val, int *tronc);
void    			ft_print_dd(flag_t *check_val);
void				ft_print_c(flag_t *check_val);
void        		ft_print_c_w(flag_t *check_val);
void        		ft_print_c_z(flag_t *check_val);
void        		ft_print_c_pz(flag_t *check_val);
void    			ft_print_c_wz(flag_t *check_val);
void				ft_print_perc(flag_t *check_val);
void    			ft_print_percw(flag_t *check_val);
void    			ft_print_percd(flag_t *check_val);
void				ft_print_u(flag_t *check_val);
void    			ft_print_uw(flag_t *check_val);
void    			ft_print_up(flag_t *check_val);
void    			ft_print_uwp(flag_t *check_val);
void    			ft_print_uwp2(flag_t *check_val, int *tronc);
void    			ft_print_ud(flag_t *check_val);
void				ft_print_x(flag_t *check_val);
void    			ft_print_xw(flag_t *check_val);
void    			ft_print_xp(flag_t *check_val);
void    			ft_print_xwp(flag_t *check_val);
void    			ft_print_xwp2(flag_t *check_val, int *tronc);
void    			ft_print_xd(flag_t *check_val);
void				ft_print_X(flag_t *check_val);
void    			ft_print_Xw(flag_t *check_val);
void    			ft_print_Xp(flag_t *check_val);
void    			ft_print_Xwp(flag_t *check_val);
void    			ft_print_Xwp2(flag_t *check_val, int *tronc);
void    			ft_print_Xd(flag_t *check_val);
void				ft_print_s(flag_t *check_val);
void    			ft_print_sw(flag_t *check_val);
void    			ft_print_sp(flag_t *check_val);
void    			ft_print_swp(flag_t *check_val);
void    			ft_print_swp2(flag_t *check_val, int *tronc);
void    			ft_print_sd(flag_t *check_val);
void				ft_print_p(flag_t *check_val);
void    			ft_print_pw(flag_t *check_val);
void    			ft_print_pp(flag_t *check_val);
void    			ft_print_pwp(flag_t *check_val);
void    			ft_print_pwp2(flag_t *check_val, int *tronc);
void    			ft_print_pd(flag_t *check_val);


#endif
