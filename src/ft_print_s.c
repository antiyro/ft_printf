/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:26:49 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/10 14:33:07 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_print_sw(t_struc *check_val)
{
	int i;

	i = 0;
	if (!check_val->s)
		check_val->s = ft_strdup(va_arg(*check_val->arg, char*));
	if (!check_val->s)
	{
		free(check_val->s);
		check_val->s = NULL;
		check_val->s = ft_strdup("(null)");
	}
	if (check_val->less)
		ft_putstr(check_val->s, check_val);
	while (i < check_val->width - (int)ft_strlen(check_val->s))
	{
		ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putstr(check_val->s, check_val);
	free(check_val->s);
	check_val->s = NULL;
}

void	ft_print_sp(t_struc *check_val)
{
	int i;

	i = 0;
	if (!check_val->s)
		check_val->s = ft_strdup(va_arg(*check_val->arg, char*));
	if (!check_val->s)
	{
		free(check_val->s);
		check_val->s = NULL;
		check_val->s = ft_strdup("(null)");
	}
	while (i < check_val->precision && check_val->s[i])
	{
		ft_putchar(check_val->s[i], check_val);
		i++;
	}
	free(check_val->s);
	check_val->s = NULL;
}

void	ft_print_swp(t_struc *check_val)
{
	int i;
	int tronc;

	i = 0;
	if (!check_val->s)
		check_val->s = ft_strdup(va_arg(*check_val->arg, char*));
	if (!check_val->s)
	{
		free(check_val->s);
		check_val->s = NULL;
		check_val->s = ft_strdup("(null)");
	}
	ft_filltroncstr(&tronc, check_val);
	if (check_val->less)
	{
		while ((i < check_val->precision) && check_val->s[i])
		{
			ft_putchar(check_val->s[i], check_val);
			i++;
		}
	}
	ft_print_swp2(check_val, &tronc);
}

void	ft_print_swp2(t_struc *check_val, int *tronc)
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
		while (i < check_val->precision && check_val->s[i])
		{
			ft_putchar(check_val->s[i], check_val);
			i++;
		}
	}
	free(check_val->s);
	check_val->s = NULL;
}

void	ft_print_sd(t_struc *check_val)
{
	int i;

	i = 0;
	check_val->s = ft_strdup(va_arg(*check_val->arg, char*));
	if (!check_val->s)
	{
		free(check_val->s);
		check_val->s = NULL;
		check_val->s = ft_strdup("(null)");
	}
	if (check_val->width > 0)
		ft_print_swp(check_val);
	return ;
	free(check_val->s);
	check_val->s = NULL;
}
