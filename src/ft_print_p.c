/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_p(flag_t *check_val)
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
        ft_putstr(ft_convert_p(((unsigned long long)(va_arg(*check_val->arg, void*))), 16), check_val);
    }
}

void	ft_print_pw(flag_t *check_val)
{
	int i;

	i = 0;
	if (!check_val->p)
		check_val->p = ft_strjoin("0x", ft_convert_p(((unsigned long long)(va_arg(*check_val->arg, void*))), 16));
	if (check_val->less)
		ft_putstr(check_val->p, check_val);
	while (i < check_val->width - (int)ft_strlen(check_val->p))
	{
		if (check_val->zero)
			ft_putchar('0', check_val);
		else
			ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->p, check_val);
}

void	ft_print_pp(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->p = ft_strjoin("0x", ft_convert_p(((unsigned long long)(va_arg(*check_val->arg, void*))), 16));
	if (check_val->less)
		ft_putstr(check_val->p, check_val);
	while (i < check_val->precision - (int)ft_strlen(check_val->p))
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->p, check_val);
}

void	ft_print_pwp(flag_t *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->p = ft_strjoin("0x", ft_convert_p(((unsigned long long)(va_arg(*check_val->arg, void*))), 16));
	ft_filltroncx(&tronc, check_val);
	if (check_val->less)
	{
		while (i < check_val->precision - (int)ft_strlen(check_val->p))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->p, check_val);
	}
	ft_print_pwp2(check_val, &tronc);
}

void	ft_print_pwp2(flag_t *check_val, int *tronc)
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
		while (i < check_val->precision - (int)ft_strlen(check_val->p))
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putstr(check_val->p, check_val);
	}
}

void	ft_print_pd(flag_t *check_val)
{
	int i;
	int tronc;

	i = 0;
	check_val->p = ft_strjoin("0x", ft_convert_p(((unsigned long long)(va_arg(*check_val->arg, void*))), 16));
	ft_filltroncp(&tronc, check_val);
	if (check_val->less && check_val->p[0] != '0')
		ft_putstr(check_val->p, check_val);
	while (i < check_val->width - tronc)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less && check_val->p[0] != '0')
		ft_putstr(check_val->p, check_val);
}
