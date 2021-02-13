/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:39 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/13 14:28:43 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_p(t_struc *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_pd(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_pw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_pp(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_pwp(check_val);
	else
	{
		ft_putstr("0x", check_val);
		ft_putstr(ft_convert_p(((unsigned long long)
			(va_arg(*check_val->arg, void*))), 16), check_val);
	}
}

void	ft_print_d(t_struc *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_dd(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_dw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_dp(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_dwp(check_val);
	else
		ft_putnbr(va_arg(*check_val->arg, int), check_val);
}

void	ft_print_c(t_struc *check_val)
{
	if (check_val->zero && check_val->width)
		ft_print_c_z(check_val);
	else if (check_val->width && !check_val->zero)
		ft_print_c_w(check_val);
	else
		ft_putchar(va_arg(*check_val->arg, int), check_val);
}

void	ft_print_s(t_struc *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_sd(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_sw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_sp(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_swp(check_val);
	else
	{
		check_val->s = ft_strdup(va_arg(*check_val->arg, char*));
		if (!check_val->s)
		{
			free(check_val->s);
			check_val->s = NULL;
			check_val->s = ft_strdup("(null)");
		}
		ft_putstr(check_val->s, check_val);
	}
}
