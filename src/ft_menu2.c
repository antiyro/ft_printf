/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:53 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/13 14:28:55 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_u(flag_t *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_ud(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_uw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_up(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_uwp(check_val);
	else
		ft_putstr(ft_convert_u(va_arg(*check_val->arg, int), 10), check_val);
}

void	ft_print_x(flag_t *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_xd(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_xw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_xp(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_xwp(check_val);
	else
		ft_putstr(ft_convert_x(va_arg(*check_val->arg, int), 16), check_val);
}

void	ft_print_xmaj(flag_t *check_val)
{
	if (check_val->dot && check_val->dot != 2)
		ft_print_xmajd(check_val);
	else if (check_val->width && !check_val->precision)
		ft_print_xmajw(check_val);
	else if (check_val->precision && !check_val->width)
		ft_print_xmajp(check_val);
	else if (check_val->precision && check_val->width)
		ft_print_xmajwp(check_val);
	else
		ft_putstr(ft_convert_xmaj(va_arg(*check_val->arg, int), 16), check_val);
}
