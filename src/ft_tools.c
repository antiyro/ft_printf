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

char *ft_convert_maj(unsigned int num, int base)
{
	static char hexadecimal_base[]= "0123456789ABCDEF";
	char *ptr;

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
		*--ptr = hexadecimal_base[num%base];
		num /= base;
	}
	return(ptr);
}

char *ft_convert_min(unsigned int num, int base)
{
	static char hexadecimal_base[]= "0123456789abcdef";
	char *ptr;

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
		*--ptr = hexadecimal_base[num%base];
		num /= base;
	}
	return(ptr);
}

void		init_flag_t(flag_t *check_flag)
{
	check_flag->arg_t = '\0';
	check_flag->less = 0;
	check_flag->zero = 0;
	check_flag->precision = 0;
	check_flag->dot = 0;
	check_flag->star = 0;
	check_flag->width = 0;
	//completer avec les autres flags
}

int					ft_flag_size(const char *format)
{
	int i;
	int count;

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