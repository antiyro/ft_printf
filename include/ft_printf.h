/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:52 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/05 13:33:05 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_struc
{
	va_list	*arg;
	char	arg_t;
	int		ret;
	int		d;
	int		c;
	char	perc;
	char	*s;
	char	*p;
	int		pnull;
	char	*u;
	char	*x;
	char	*xmaj;
	char	*flag;
	int		zero;
	int		less;
	int		precision;
	int		dot;
	int		star;
	int		width;
}				t_struc;

int				ft_check_flag(char c);
int				ft_check_args(char c);
void			ft_valneg(t_struc *check_val);
void			ft_filltronc(int *tronc, t_struc *check_val);
void			ft_filltroncu(int *tronc, t_struc *check_val);
void			ft_filltroncx(int *tronc, t_struc *check_val);
void			ft_filltroncxmaj(int *tronc, t_struc *check_val);
void			ft_filltroncp(int *tronc, t_struc *check_val);
void			ft_filltroncperc(int *tronc, t_struc *check_val);
void			ft_filltroncstr(int *tronc, t_struc *check_val);
void			init_t_struc(t_struc *check_flag);
char			*ft_convert_xmaj(unsigned int num, int base);
char			*ft_convert_x(unsigned int num, int base);
char			*ft_convert_u(int nb, int base);
char			*ft_convert_uneg(int num);
char			*ft_convert_p(unsigned long long nb, int base);
int				ft_convlen(unsigned int num);
int				ft_convlenp(unsigned long long num);
char			*ft_reverse(char *str, unsigned long long num);
int				ft_flag_size(const char *format);
int				ft_printf(const char *format, ...);
void			ft_parsing(const char *format, t_struc *check_val);
void			ft_parsing2(const char *format, t_struc *check_val, int i);
void			ft_parsingargs(const char *format, int i, t_struc *check_val);
void			ft_parsingflags(t_struc *check_val);
void			ft_verify_width(t_struc *check_val);
void			ft_verify_width2(t_struc *check_val);
void			ft_verify_width3(t_struc *check_val, int *first, int *i);
void			ft_verify_precision(t_struc *check_val);
void			ft_verify_precision2(t_struc *check_val, int *i);
void			ft_verify_precision3(t_struc *check_val, int *i);
void			ft_verify_precision4(t_struc *check_val);
void			ft_verify_less(t_struc *check_val);
void			ft_printcontrol(const char *format,
	va_list arg, t_struc *check_val);
void			ft_print_percent(t_struc *check_val);
void			ft_printargs(const char *format, int i, t_struc *check_val);
void			ft_print_d(t_struc *check_val);
void			ft_print_dw(t_struc *check_val);
void			ft_print_dp(t_struc *check_val);
void			ft_print_dwp(t_struc *check_val);
void			ft_print_dwp2(t_struc *check_val, int *tronc);
void			ft_print_dd(t_struc *check_val);
void			ft_print_c(t_struc *check_val);
void			ft_print_c_w(t_struc *check_val);
void			ft_print_c_z(t_struc *check_val);
void			ft_print_c_pz(t_struc *check_val);
void			ft_print_c_wz(t_struc *check_val);
void			ft_print_perc(t_struc *check_val);
void			ft_print_percw(t_struc *check_val);
void			ft_print_percd(t_struc *check_val);
void			ft_print_u(t_struc *check_val);
void			ft_print_uw(t_struc *check_val);
void			ft_print_up(t_struc *check_val);
void			ft_print_uwp(t_struc *check_val);
void			ft_print_uwp2(t_struc *check_val, int *tronc);
void			ft_print_ud(t_struc *check_val);
void			ft_print_x(t_struc *check_val);
void			ft_print_xw(t_struc *check_val);
void			ft_print_xp(t_struc *check_val);
void			ft_print_xwp(t_struc *check_val);
void			ft_print_xwp2(t_struc *check_val, int *tronc);
void			ft_print_xd(t_struc *check_val);
void			ft_print_xmaj(t_struc *check_val);
void			ft_print_xmajw(t_struc *check_val);
void			ft_print_xmajp(t_struc *check_val);
void			ft_print_xmajwp(t_struc *check_val);
void			ft_print_xmajwp2(t_struc *check_val, int *tronc);
void			ft_print_xmajd(t_struc *check_val);
void			ft_print_s(t_struc *check_val);
void			ft_print_sw(t_struc *check_val);
void			ft_print_sp(t_struc *check_val);
void			ft_print_swp(t_struc *check_val);
void			ft_print_swp2(t_struc *check_val, int *tronc);
void			ft_print_sd(t_struc *check_val);
void			ft_print_p(t_struc *check_val);
void			ft_print_pw(t_struc *check_val);
void			ft_print_pp(t_struc *check_val);
void			ft_print_pwp(t_struc *check_val);
void			ft_print_pwp2(t_struc *check_val, int *tronc);
void			ft_print_pd(t_struc *check_val);

#endif
