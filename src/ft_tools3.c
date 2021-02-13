/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:16:07 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/13 13:16:18 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

void	ft_filltroncx(int *tronc, flag_t *check_val)
{
	if ((int)ft_strlen(check_val->x) <= check_val->precision)
	{
		if (check_val->x < 0)
			*tronc = check_val->precision + 1;
		else
			*tronc = check_val->precision;
	}
	else
		*tronc = (int)ft_strlen(check_val->x);
	if (check_val->dot && !check_val->precision &&
		check_val->x[0] == '0' && check_val->dot != 2)
		*tronc = 0;
}

void	ft_filltroncxmaj(int *tronc, flag_t *check_val)
{
	if ((int)ft_strlen(check_val->xmaj) <= check_val->precision)
	{
		if (check_val->xmaj < 0)
			*tronc = check_val->precision + 1;
		else
			*tronc = check_val->precision;
	}
	else
		*tronc = (int)ft_strlen(check_val->xmaj);
	if (check_val->dot && !check_val->precision &&
		check_val->xmaj[0] == '0' && check_val->dot != 2)
		*tronc = 0;
}

void	ft_filltroncperc(int *tronc, flag_t *check_val)
{
	if (1 <= check_val->precision)
		*tronc = check_val->precision;
	else
		*tronc = 1;
}

void	ft_filltroncstr(int *tronc, flag_t *check_val)
{
	if ((int)ft_strlen(check_val->s) <= check_val->precision)
		*tronc = (int)ft_strlen(check_val->s);
	else
		*tronc = check_val->precision;
}

void	ft_filltroncp(int *tronc, flag_t *check_val)
{
	if ((int)ft_strlen(check_val->p) <= check_val->precision)
	{
		if (check_val->p < 0)
			*tronc = check_val->precision + 1;
		else
			*tronc = check_val->precision;
	}
	else
		*tronc = (int)ft_strlen(check_val->p);
}
