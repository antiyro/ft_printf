/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_uw(t_struc *check_val)
{
	int i;

	i = 0;
	if (!check_val->u)
		check_val->u = ft_convert_u(va_arg(*check_val->arg, int), 10);
	if (check_val->less)
		ft_putstr(check_val->u, check_val);
	while (i < check_val->width - (int)ft_strlen(check_val->u))
	{
		if (check_val->zero)
			ft_putchar('0', check_val);
		else
			ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->u, check_val);
}

void	ft_print_up(t_struc *check_val)
{
	int i;

	i = 0;
	check_val->u = ft_convert_u(va_arg(*check_val->arg, int), 10);
	if (check_val->less)
		ft_putstr(check_val->u, check_val);
	while (i < check_val->precision - (int)ft_strlen(check_val->u))
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->u, check_val);
}

void	ft_print_uwp(t_struc *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->u = ft_convert_u(va_arg(*check_val->arg, int), 10);
	ft_filltroncu(&tronc, check_val);
	if (check_val->less)
	{
		while (i < check_val->precision - (int)ft_strlen(check_val->u))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->u, check_val);
	}
	ft_print_uwp2(check_val, &tronc);
}

void	ft_print_uwp2(t_struc *check_val, int *tronc)
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
		while (i < check_val->precision - (int)ft_strlen(check_val->u))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->u, check_val);
	}
}

void	ft_print_ud(t_struc *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->u = ft_convert_u(va_arg(*check_val->arg, int), 10);
	ft_filltroncu(&tronc, check_val);
	if (check_val->less && check_val->u[0] != '0')
		ft_putstr(check_val->u, check_val);
	while (i < check_val->width - tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less && check_val->u[0] != '0')
		ft_putstr(check_val->u, check_val);
}
