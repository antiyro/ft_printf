/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:27:21 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/05 17:57:28 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

void		init_t_struc(t_struc *check_val)
{
	check_val->arg_t = '\0';
	check_val->d = 0;
	check_val->c = 0;
	check_val->u = 0;
	check_val->x = 0;
	check_val->xmaj = 0;
	check_val->s = 0;
	check_val->p = 0;
	check_val->perc = '\0';
	check_val->less = 0;
	check_val->zero = 0;
	check_val->precision = 0;
	check_val->dot = 0;
	check_val->star = 0;
	check_val->width = 0;
}

int			ft_flag_size(const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			while (ft_check_flag(format[i]))
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

void		ft_filltronc(int *tronc, t_struc *check_val)
{
	if ((int)ft_nbrlen(check_val->d) <= check_val->precision)
	{
		if (check_val->d < 0)
			*tronc = check_val->precision + 1;
		else
			*tronc = check_val->precision;
	}
	else
		*tronc = (int)ft_nbrlen(check_val->d);
	if (check_val->dot && !check_val->precision &&
		!check_val->d && check_val->dot != 2)
		*tronc = 0;
}

void		ft_filltroncu(int *tronc, t_struc *check_val)
{
	if ((int)ft_strlen(check_val->u) <= check_val->precision)
	{
		if (check_val->u < 0)
			*tronc = check_val->precision + 1;
		else
			*tronc = check_val->precision;
	}
	else
		*tronc = (int)ft_strlen(check_val->u);
	if (check_val->dot && !check_val->precision &&
		check_val->u[0] == '0' && check_val->dot != 2)
		*tronc = 0;
}
