/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:02:48 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/19 11:02:50 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

void	ft_print_perc(flag_t *check_val)
{
	if (check_val->zero && check_val->width)
		ft_print_perc_z(check_val);
	else if (check_val->width && !check_val->zero)
		ft_print_perc_w(check_val);
	else
		ft_putchar('%', check_val);
}

void	ft_print_perc_w(flag_t *check_val)
{
	int i;

	check_val->perc = '%';
	i = 0;
	if (check_val->less)
		ft_putchar(check_val->perc, check_val);
	while (i < check_val->width - 1)
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putchar(check_val->perc, check_val);
}

void	ft_print_perc_z(flag_t *check_val)
{
	int i;

	check_val->perc = '%';
	i = 0;
	if (check_val->perc < 0)
	{
		ft_putchar('-', check_val);
		check_val->perc *= -1;
		check_val->width -= 1;
	}
	while (i < check_val->width - 1)
	{
		ft_putchar('0', check_val);
		i++;
	}
	ft_putchar(check_val->perc, check_val);
}

void	ft_print_perc_pz(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->perc = '%';
	if (check_val->perc < 0)
	{
		ft_putchar('-', check_val);
		check_val->perc *= -1;
	}
	while (i < check_val->width - 1)
	{
		ft_putchar('0', check_val);
		i++;
	}
	if (check_val->perc || check_val->star || check_val->width)
		ft_putchar(check_val->perc, check_val);
}

void	ft_print_perc_wz(flag_t *check_val)
{
	int i;

	i = 0;
	check_val->perc = '%';
	if (check_val->perc < 0)
	{
		ft_putchar('-', check_val);
		check_val->perc *= -1;
	}
	while (i <= check_val->precision - 1)
	{
		ft_putchar(' ', check_val);
		i++;
	}
}

void	ft_print_percwp2(flag_t *check_val, int *tronc)
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
		while (i < check_val->precision - 1)
		{
			ft_putchar('0', check_val);
			i++;
		}
		ft_putchar(check_val->perc, check_val);
	}
}