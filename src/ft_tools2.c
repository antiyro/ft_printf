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

int		ft_check_flag(char c)
{
	if (c != 'c' && c != 'd' && c != 's' &&
			c != 'u' && c != 'x' && c != 'X' &&
				c != '%' && c != 'i' && c != 'p')
		return (1);
	return (0);
}

int		ft_check_args(char c)
{
	if (c == 'c' || c == 'd' || c == 's' ||
			c == 'u' || c == 'x' || c == 'X' ||
				c == '%' || c == 'i' || c == 'p')
		return (1);
	return (0);
}

int		ft_convlen(unsigned int num)
{
	int i;

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

char	*ft_reverse(char *str, unsigned long long num)
{
	int i;
	int j;
	char tmp;

	i = 0;
	j = ft_convlen(num) - 1;
	while (i != j && str[i])
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	str[ft_convlen(num)] = '\0';
	return (str);
}

char *ft_convert_u(int num, int base)
{
	static char hexadecimal_base[]= "0123456789";
	char *ptr;
	if (num < 0)
		return(ft_convert_uneg(num));
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

char *ft_convert_uneg(int num)
{
	char *ptr;
	long long result;

	num *= -1;
	result = 4294967295 - num + 1;
	ptr = ft_strdup(ft_itoa(result));
	return(ptr);
}

char *ft_convert_p(unsigned long long num, int base)
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

void	ft_valneg(flag_t *check_val)
{
	check_val->d *= -1;
	ft_putchar('-', check_val);
}

void	tester(char c)
{
	write(1, &c, 1);
}

void	ft_filltronc(int *tronc, flag_t *check_val)
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
	if (check_val->dot && !check_val->precision && !check_val->d && check_val->dot != 2)
		*tronc = 0;
}

void	ft_filltroncstr(int *tronc, flag_t *check_val)
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
	if (check_val->dot && !check_val->precision && !check_val->u && check_val->dot != 2)
		*tronc = 0;
}