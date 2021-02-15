/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:36:14 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/15 09:52:17 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void		ft_parsingflags(t_struc *check_val)
{
	int		i;

	i = 0;
	ft_verify_width(check_val);
	while (check_val->flag[i])
	{
		if (check_val->flag[i] == '.')
			ft_verify_precision(check_val);
		i++;
	}
	ft_verify_less(check_val);
}

void		ft_parsingargs(const char *format, int i, t_struc *check_val)
{
	if (format[i] == '%')
		check_val->arg_t = '%';
	else if (format[i] == 'd')
		check_val->arg_t = format[i];
	else if (format[i] == 'c')
		check_val->arg_t = format[i];
	else if (format[i] == 's')
		check_val->arg_t = 's';
	else if (format[i] == 'u')
		check_val->arg_t = format[i];
	else if (format[i] == 'x')
		check_val->arg_t = format[i];
	else if (format[i] == 'X')
		check_val->arg_t = format[i];
	else if (format[i] == 'i')
		check_val->arg_t = format[i];
	else if (format[i] == 'p')
		check_val->arg_t = format[i];
}

void		ft_parsing(const char *format, t_struc *check_val)
{
	int		i;
	int		j;

	i = 0;
	while (format[i] && i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			j = 0;
			if (!(check_val->flag = (char *)malloc(sizeof(char)
				* (ft_flag_size(format) + 1))))
				return ;
			i += 1;
			while (ft_check_flag(format[i]))
				check_val->flag[j++] = format[i++];
			check_val->flag[j] = '\0';
			ft_parsing2(format, check_val, i);
			i++;
		}
		if (format[i] && format[i] != '%')
		{
			ft_putchar(format[i], check_val);
			i++;
		}
	}
}

void		ft_parsing2(const char *format, t_struc *check_val, int i)
{
	init_t_struc(check_val);
	ft_parsingargs(format, i, check_val);
	if (check_val->flag)
		ft_parsingflags(check_val);
	free(check_val->flag);
	check_val->flag = NULL;
	ft_printargs(format, i, check_val);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	t_struc	check_val;

	check_val.ret = 0;
	va_start(arg, format);
	check_val.arg = &arg;
	ft_parsing(format, &check_val);
	va_end(arg);
	return (check_val.ret);
}
