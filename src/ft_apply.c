/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:59:47 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/11 08:59:50 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/printf.h"

void    ft_printargs(const char *format, int i, flag_t *check_val)
{
    if (format[i] == '%')
        ft_print_perc(check_val);
    if (format[i] == 'd')
        ft_print_d(check_val);
    else if (format[i] == 'c')
        ft_print_c(check_val);
    else if (format[i] == 's')
        ft_print_s(check_val);
    else if (format[i] == 'u')
        ft_print_u(check_val);
    else if (format[i] == 'x')
        ft_print_x(check_val);
    else if (format[i] == 'X')
        ft_print_X(check_val);
    else if (format[i] == 'i')
        ft_print_d(check_val);
    else if (format[i] == 'p')
        ft_print_p(check_val);
}