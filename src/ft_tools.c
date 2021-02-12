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

char *ft_convert_X(unsigned int num, int base)
{
	static char hexadecimal_base[]= "0123456789ABCDEF";
	char *ptr;
	int i;

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
		ptr[--i] = hexadecimal_base[num%base];
		num /= base;
	}
	return(ptr);
}

char *ft_convert_x(unsigned int num, int base)
{
	static char hexadecimal_base[]= "0123456789abcdef";
	char *ptr;
	int i;

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
		ptr[--i] = hexadecimal_base[num%base];
		num /= base;
	}
	return(ptr);
}

char *ft_convert_p(unsigned long long num, int base)
{
	static char hexadecimal_base[]= "0123456789abcdef";
	char *ptr;
	int i;

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
		ptr[--i] = hexadecimal_base[num%base];
		num /= base;
	}
	return(ptr);
}

void		init_flag_t(flag_t *check_val)
{
	check_val->arg_t = '\0';
	check_val->d = 0;
	check_val->c = 0;
	check_val->u = 0;
	check_val->x = 0;
	check_val->X = 0;
	check_val->s = 0;
	check_val->p = 0;
	check_val->perc = '\0';
	check_val->less = 0;
	check_val->zero = 0;
	check_val->precision = 0;
	check_val->dot = 0;
	check_val->star = 0;
	check_val->width = 0;
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