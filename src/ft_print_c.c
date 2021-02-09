/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:02:48 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/19 11:02:50 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

void	ft_print_c(flag_t *check_val)
{
	if (check_val->zero && check_val->width)
		ft_print_c_z(check_val);
	else if (check_val->width && !check_val->zero)
		ft_print_c_w(check_val);
	else
		ft_putchar(va_arg(*check_val->arg, int), check_val);
}

void	ft_print_c_w(flag_t *check_val)
{
	int i;

	check_val->c = va_arg(*check_val->arg, int);
	i = 0;
	if (check_val->less)
		ft_putchar(check_val->c, check_val);
	while (i < check_val->width - 1)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putchar(check_val->c, check_val);
}

void	ft_print_c_z(flag_t *check_val)
{
	int i;

	check_val->c = va_arg(*check_val->arg, int);
	i = 0;
	if (check_val->c < 0)
	{
		ft_putchar('-', check_val);
		check_val->c *= -1;
		check_val->width -= 1;
	}
	while (i < check_val->width - ft_nbrlen(check_val->c))
	{
		ft_putchar('0', check_val);
		i++;
	}
	ft_putchar(check_val->c, check_val);
}

void	ft_print_c_pz(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->c = va_arg(*check_val->arg, int);
	if (check_val->c < 0)
	{
		ft_putchar('-', check_val);
		check_val->c *= -1;
	}
	while (i < check_val->width - ft_nbrlen(check_val->c))
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (check_val->c || check_val->star || check_val->width)
		ft_putchar(check_val->c, check_val);
}

void	ft_print_c_wz(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->c = va_arg(*check_val->arg, int);
	if (check_val->c < 0)
	{
		ft_putchar('-', check_val);
		check_val->c *= -1;
	}
	while (i <= check_val->precision - ft_nbrlen(check_val->c))
	{
		ft_putchar(' ', check_val);
		i++;
	}
}
