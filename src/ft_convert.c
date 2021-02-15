/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:20:44 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/13 13:20:47 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

char			*ft_convert_u(int num, int base, t_struc *check_val)
{
	static char hexadecimal_base[] = "0123456789";
	int			i;

	i = ft_convlenu(num);
	if (num < 0)
		return (ft_convert_uneg(num, check_val));
	if (!(check_val->container = malloc(sizeof(char) * (ft_convlenu(num) + 1))))
		return (NULL);
	check_val->container[i] = '\0';
	if (num == 0)
	{
		check_val->container[--i] = '0';
		return (check_val->container);
	}
	while (num != 0)
	{
		check_val->container[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (check_val->container);
}

char			*ft_convert_uneg(int num, t_struc *check_val)
{
	long long	result;

	num *= -1;
	result = 4294967295 - num + 1;
	check_val->container = ft_strdup(ft_itoa(result));
	return (check_val->container);
}

char			*ft_convert_xmaj(unsigned int num, int base, t_struc *check_val)
{
	static char hexadecimal_base[] = "0123456789ABCDEF";
	int			i;

	i = ft_convlen(num);
	if (!(check_val->container = malloc(sizeof(char) * ft_convlen(num) + 1)))
		return (NULL);
	check_val->container[i] = '\0';
	if (num == 0)
	{
		check_val->container[--i] = '0';
		return (check_val->container);
	}
	while (num != 0)
	{
		check_val->container[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (check_val->container);
}

char			*ft_convert_x(unsigned int num, int base, t_struc *check_val)
{
	static char hexadecimal_base[] = "0123456789abcdef";
	int			i;

	i = ft_convlen(num);
	if (!(check_val->container = malloc(sizeof(char) * (ft_convlen(num) + 1))))
		return (NULL);
	check_val->container[i] = '\0';
	if (num == 0)
	{
		check_val->container[--i] = '0';
		return (check_val->container);
	}
	while (num != 0)
	{
		check_val->container[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (check_val->container);
}

char			*ft_convert_p(unsigned long long num, int base,
	t_struc *check_val)
{
	static char	hexadecimal_base[] = "0123456789abcdef";
	int			i;

	i = ft_convlenp(num);
	if (!(check_val->container = malloc(sizeof(char) * (ft_convlenp(num) + 1))))
		return (NULL);
	check_val->container[i] = '\0';
	if (num == 0)
	{
		check_val->container[--i] = '0';
		return (check_val->container);
	}
	while (num != 0)
	{
		check_val->container[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (check_val->container);
}
