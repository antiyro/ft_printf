/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:05:15 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/06 16:08:54 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_verify_width(flag_t *check_val)
{
	int i;
	int first;

	i = 0;
	first = 1;
	while (check_val->flag[i])
	{
		if (check_val->flag[i] == '.')
			break ;
		if (check_val->flag[i] == '-')
			check_val->less = 1;
		if (check_val->flag[i] == '*')
		{
			ft_verify_width2(check_val);
			break ;
		}
		if (ft_isdigit(check_val->flag[i]))
			ft_verify_width3(check_val, &first, &i);
		i++;
	}
	if (!check_val->width && check_val->less)
		check_val->less = 0;
}

void	ft_verify_width2(flag_t *check_val)
{
	check_val->width = va_arg(*check_val->arg, int);
	if (check_val->width < 0)
	{
		check_val->width *= -1;
		check_val->less = 1;
	}
}

void	ft_verify_width3(flag_t *check_val, int *first, int *i)
{
	if (*first && check_val->flag[*i] == '0' && !check_val->less)
		check_val->zero = 1;
	check_val->width = check_val->width * 10 +
		(check_val->flag[*i] - 48);
	*first = 0;
}

void	ft_verify_less(flag_t *check_val)
{
	if (check_val->less)
		check_val->zero = 0;
	if (check_val->precision && check_val->arg_t != 's' && check_val->arg_t
		!= '%' && check_val->arg_t != 'c' && check_val->arg_t != 'p')
		check_val->zero = 0;
}
