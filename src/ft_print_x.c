/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

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

void	ft_print_xw(flag_t *check_val)
{
	int i;

	i = 0;
	if (!check_val->x)
		check_val->x = ft_convert_x(va_arg(*check_val->arg, int), 16);
	if (check_val->less)
		ft_putstr(check_val->x, check_val);
	while (i < check_val->width - (int)ft_strlen(check_val->x))
	{
		if (check_val->zero)
			ft_putchar('0', check_val);
		else
			ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->x, check_val);
}

void	ft_print_xp(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->x = ft_convert_x(va_arg(*check_val->arg, int), 16);
	if (check_val->less)
		ft_putstr(check_val->x, check_val);
	while (i < check_val->precision - (int)ft_strlen(check_val->x))
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->x, check_val);
}

void	ft_print_xwp(flag_t *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->x = ft_convert_x(va_arg(*check_val->arg, int), 16);
	ft_filltroncx(&tronc, check_val);
	if (check_val->less)
	{
		while (i < check_val->precision - (int)ft_strlen(check_val->x))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->x, check_val);
	}
	ft_print_xwp2(check_val, &tronc);
}

void	ft_print_xwp2(flag_t *check_val, int *tronc)
{
	int i;

	i = 0;
	while (i < check_val->width - *tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	i = 0;
	if (!check_val->less)
	{
		while (i < check_val->precision - (int)ft_strlen(check_val->x))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->x, check_val);
	}
}

void	ft_print_xd(flag_t *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->x = ft_convert_x(va_arg(*check_val->arg, int), 16);
	ft_filltroncx(&tronc, check_val);
	if (check_val->less && check_val->x[0] != '0')
		ft_putstr(check_val->x, check_val);
	while (i < check_val->width - tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less && check_val->x[0] != '0')
		ft_putstr(check_val->x, check_val);
}
