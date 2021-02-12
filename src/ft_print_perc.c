/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
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
	if (check_val->width)
		ft_print_percw(check_val);
	else
		ft_putchar('%', check_val);
}

void	ft_print_percw(flag_t *check_val)
{
	int i;

	i = 0;
	if (!check_val->perc)
		check_val->perc = '%';
	if (check_val->less)
		ft_putchar(check_val->perc, check_val);
	while (i < check_val->width - 1)
	{
		if (check_val->zero)
			ft_putchar('0', check_val);
		else
			ft_putchar(' ', check_val);
		i++;
	}
	if (!check_val->less)
		ft_putchar(check_val->perc, check_val);
}
