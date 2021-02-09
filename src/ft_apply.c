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

/*void    ft_print_sdi(va_list arg, flag_t *check_val)
{
    int i = 0;
    int dlen;

    int star;
    star = va_arg(arg, int);
    check_val->d = va_arg(arg, int);
    dlen = ft_nbrlen(check_val->d);
    if (star < 0)
    {
        check_val->less = 1;
        check_val->zero = 0;
        star *= -1;
    }
    if (check_val->less)
        ft_putnbr(check_val->d, check_val);
    if (check_val->d < 0 && check_val->zero && check_val->d != -2147483648)
    {
        ft_putchar('-', check_val);
        check_val->d *= -1;
    }
    if (check_val->zero)
    {
        while (i < star - dlen)
        {
           ft_putchar('0', check_val);
           i++;
        }
    }
    else
    {
        while (i < star - dlen)
        {
           ft_putchar(' ', check_val);
           i++;
        }
    }
    if (!check_val->less)
        ft_putnbr(check_val->d, check_val);
}

void    ft_print_sxi(va_list arg, flag_t *check_val)
{
    int i = 0;

    int star;
    star = va_arg(arg, int);
    check_val->x = ft_convert_min(va_arg(arg, unsigned int), 16);
    if (star < 0)
        check_val->less = 1;
    if (check_val->less)
        ft_putstr(check_val->x, check_val);
    if (check_val->zero)
    {
        while (i < star - (int)ft_strlen(check_val->x))
        {
           ft_putchar('0', check_val);
           i++;
        }
    }
    else
    {
        while (i < star - (int)ft_strlen(check_val->x))
        {
           ft_putchar(' ', check_val);
           i++;
        }
    }
    if (!check_val->less)
        ft_putstr(check_val->x, check_val);
}

void    ft_print_sXi(va_list arg, flag_t *check_val)
{
    int i = 0;

    int star;
    star = va_arg(arg, int);
    check_val->X = ft_convert_maj(va_arg(arg, unsigned int), 16);
    if (star < 0)
        check_val->less = 1;
    if (check_val->less)
        ft_putstr(check_val->X, check_val);
    if (check_val->zero)
    {
        while (i < star - (int)ft_strlen(check_val->X))
        {
           ft_putchar('0', check_val);
           i++;
        }
    }
    else
    {
        while (i < star - (int)ft_strlen(check_val->X))
        {
           ft_putchar(' ', check_val);
           i++;
        }
    }
    if (!check_val->less)
        ft_putstr(check_val->X, check_val);
}

void    ft_print_sui(va_list arg, flag_t *check_val)
{
    int i = 0;

    int star;
    star = va_arg(arg, int);
    check_val->u = ft_convert_u(va_arg(arg, unsigned int), 10);
    if (star < 0)
        check_val->less = 1;
    if (check_val->less)
        ft_putstr(check_val->u, check_val);
    if (check_val->zero)
    {
        while (i < star - (int)ft_strlen(check_val->u))
        {
           ft_putchar('0', check_val);
           i++;
        }
    }
    else
    {
        while (i < star - (int)ft_strlen(check_val->u))
        {
           ft_putchar(' ', check_val);
           i++;
        }
    }
    if (!check_val->less)
        ft_putstr(check_val->u, check_val);
}
void    ft_print_spi(va_list arg, flag_t *check_val)
{
    int i = 0;

    int star;
    star = va_arg(arg, int);
    check_val->p = ft_strjoin("0x", ft_convert_p(va_arg(arg, unsigned long long), 16));
    if (star < 0)
        check_val->less = 1;
    if (check_val->less)
        ft_putstr(check_val->p, check_val);
    if (check_val->zero)
    {
        while (i < star - (int)ft_strlen(check_val->p))
        {
           ft_putchar('0', check_val);
           i++;
        }
    }
    else
    {
        while (i < star - (int)ft_strlen(check_val->p))
        {
           ft_putchar(' ', check_val);
           i++;
        }
    }
    if (!check_val->less)
        ft_putstr(check_val->p, check_val);
}

void    ft_print_ssi(va_list arg, flag_t *check_val)
{
    int i = 0;
    int slen;
    
    int star;
    star = va_arg(arg, int);
    if (!(check_val->s = ft_strdup(va_arg(arg, char *))))
        return ;
    slen = ft_strlen(check_val->s);
    if (star < 0)
    {
        check_val->less = 1;
        star *= -1;
    }
    if (check_val->less)
    {
        while (check_val->s[i])
        {
            ft_putchar(check_val->s[i], check_val);
            i++;
        }
        i = 0;
    }
    while (i < star - slen)
    {
        ft_putchar(' ', check_val);
        i++;
    }
    if (!check_val->less)
    {
        while (check_val->s[i])
        {
            ft_putchar(check_val->s[i], check_val);
            i++;
        }
    }
}
*/

void    ft_printargs(const char *format, int i, flag_t *check_val)
{
    /*if (format[i] == '%')
        ft_putchar('%', check_val);*/
    if (format[i] == 'd')
        ft_print_d(check_val);
    else if (format[i] == 'c')
        ft_print_c(check_val);/*
    else if (format[i] == 's')
        ft_print_s(arg, check_val);*/
    else if (format[i] == 'u')
        ft_print_u(check_val);/*
    else if (format[i] == 'x')
        ft_print_x(arg, check_val);
    else if (format[i] == 'X')
        ft_print_X(arg, check_val);*/
    else if (format[i] == 'i')
        ft_print_d(check_val);/*s
    else if (format[i] == 'p')
        ft_print_p(arg, check_val);*/
}