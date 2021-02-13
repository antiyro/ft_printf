/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_dw(t_struc *check_val)
{
	int i;

	i = 0;
	if (!check_val->d)
		check_val->d = va_arg(*check_val->arg, int);
	if (check_val->d < 0 && check_val->zero && check_val->d != -2147483648)
	{
		ft_putchar('-', check_val);
		check_val->d *= -1;
		check_val->width -= 1;
	}
	if (check_val->less)
		ft_putnbr(check_val->d, check_val);
	while (i < check_val->width - (int)ft_nbrlen(check_val->d))
	{
		if (check_val->zero)
			ft_putchar('0', check_val);
		else
			ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putnbr(check_val->d, check_val);
}

void	ft_print_dp(t_struc *check_val)
{
	int i;

	i = 0;
	check_val->d = va_arg(*check_val->arg, int);
	if (check_val->d < 0 && check_val->d != -2147483648)
	{
		ft_putchar('-', check_val);
		check_val->d *= -1;
	}
	if (check_val->less)
		ft_putnbr(check_val->d, check_val);
	while (i < check_val->precision - (int)ft_nbrlen(check_val->d))
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putnbr(check_val->d, check_val);
}

void	ft_print_dwp(t_struc *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->d = va_arg(*check_val->arg, int);
	ft_filltronc(&tronc, check_val);
	if (check_val->less)
	{
		if (check_val->d < 0 && check_val->d != -2147483648)
		{
			ft_putchar('-', check_val);
			check_val->d *= -1;
		}
		while (i < check_val->precision - (int)ft_nbrlen(check_val->d))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putnbr(check_val->d, check_val);
	}
	ft_print_dwp2(check_val, &tronc);
}

void	ft_print_dwp2(t_struc *check_val, int *tronc)
{
	int i;

	i = 0;
	while (i < check_val->width - *tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (check_val->d < 0 && !check_val->less && check_val->d != -2147483648)
	{
		ft_putchar('-', check_val);
		check_val->d *= -1;
		check_val->width -= 1;
	}
	i = 0;
	if (!check_val->less)
	{
		while (i < check_val->precision - (int)ft_nbrlen(check_val->d))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putnbr(check_val->d, check_val);
	}
}

void	ft_print_dd(t_struc *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->d = va_arg(*check_val->arg, int);
	ft_filltronc(&tronc, check_val);
	if (check_val->less && check_val->d)
		ft_putnbr(check_val->d, check_val);
	while (i < check_val->width - tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less && check_val->d)
		ft_putnbr(check_val->d, check_val);
}
