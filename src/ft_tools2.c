/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 09:43:13 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/08 09:45:59 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

int				ft_check_flag(char c)
{
	if (c != 'c' && c != 'd' && c != 's' &&
			c != 'u' && c != 'x' && c != 'X' &&
				c != '%' && c != 'i' && c != 'p')
		return (1);
	return (0);
}

int				ft_check_args(char c)
{
	if (c == 'c' || c == 'd' || c == 's' ||
			c == 'u' || c == 'x' || c == 'X' ||
				c == '%' || c == 'i' || c == 'p')
		return (1);
	return (0);
}

int				ft_convlen(unsigned int num)
{
	int			i;

	i = 1;
	if (num == 0)
		return (1);
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int				ft_convlenp(unsigned long long num)
{
	int			i;

	i = 1;
	if (num == 0)
		return (1);
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int				ft_convlenu(unsigned int num)
{
	int			i;

	i = 1;
	if (num == 0)
		return (1);
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}
