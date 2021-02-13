/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:24:27 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/13 15:24:32 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void	ft_verify_precision(t_struc *check_val)
{
	int i;

	i = 0;
	while (check_val->flag[i] != '.')
		i++;
	while (check_val->flag[i])
	{
		if (check_val->flag[i] == '-')
		{
			ft_verify_precision4(check_val);
			break ;
		}
		if (check_val->flag[i] == '*')
		{
			check_val->precision = va_arg(*check_val->arg, int);
			if (check_val->precision < 0)
			{
				ft_verify_precision4(check_val);
				break ;
			}
			break ;
		}
		ft_verify_precision2(check_val, &i);
	}
	ft_verify_precision3(check_val, &i);
}

void	ft_verify_precision2(t_struc *check_val, int *i)
{
	if (ft_isdigit(check_val->flag[*i]))
		check_val->precision = check_val->precision * 10 +
			(check_val->flag[*i] - 48);
	*i += 1;
}

void	ft_verify_precision3(t_struc *check_val, int *i)
{
	if (check_val->flag[*i] == '.')
		check_val->precision = 0;
	if (!check_val->precision && check_val->dot != 2)
		check_val->dot = 1;
}

void	ft_verify_precision4(t_struc *check_val)
{
	check_val->precision = 0;
	check_val->dot = 2;
}
