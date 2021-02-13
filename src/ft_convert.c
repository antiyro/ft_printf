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

char			*ft_convert_u(int num, int base)
{
	static char hexadecimal_base[] = "0123456789";
	char		*ptr;

	if (num < 0)
		return (ft_convert_uneg(num));
	if (!(ptr = malloc(sizeof(char) * ft_convlen(num) + 1)))
		return (NULL);
	ptr = &ptr[ft_convlen(num)];
	*ptr = '\0';
	if (num == 0)
	{
		*--ptr = '0';
		return (ptr);
	}
	while (num != 0)
	{
		*--ptr = hexadecimal_base[num % base];
		num /= base;
	}
	return (ptr);
}

char			*ft_convert_uneg(int num)
{
	char		*ptr;
	long long	result;

	num *= -1;
	result = 4294967295 - num + 1;
	ptr = ft_strdup(ft_itoa(result));
	return (ptr);
}

char			*ft_convert_xmaj(unsigned int num, int base)
{
	static char hexadecimal_base[] = "0123456789ABCDEF";
	char		*ptr;
	int			i;

	i = ft_convlen(num);
	if (!(ptr = malloc(sizeof(char) * ft_convlen(num) + 1)))
		return (NULL);
	ptr[i] = '\0';
	if (num == 0)
	{
		ptr[--i] = '0';
		return (ptr);
	}
	while (num != 0)
	{
		ptr[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (ptr);
}

char			*ft_convert_x(unsigned int num, int base)
{
	static char hexadecimal_base[] = "0123456789abcdef";
	char		*ptr;
	int			i;

	i = ft_convlen(num);
	if (!(ptr = malloc(sizeof(char) * (ft_convlen(num) + 1))))
		return (NULL);
	ptr[i] = '\0';
	if (num == 0)
	{
		ptr[--i] = '0';
		return (ptr);
	}
	while (num != 0)
	{
		ptr[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (ptr);
}

char			*ft_convert_p(unsigned long long num, int base)
{
	static char	hexadecimal_base[] = "0123456789abcdef";
	char		*ptr;
	int			i;

	i = ft_convlenp(num);
	if (!(ptr = malloc(sizeof(char) * (ft_convlenp(num) + 1))))
		return (NULL);
	ptr[i] = '\0';
	if (num == 0)
	{
		ptr[--i] = '0';
		return (ptr);
	}
	while (num != 0)
	{
		ptr[--i] = hexadecimal_base[num % base];
		num /= base;
	}
	return (ptr);
}
