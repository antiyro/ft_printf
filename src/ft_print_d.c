/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:21:20 by nbouhada          #+#    #+#             */
/*   Updated: 2021/02/08 11:22:23 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/ft_printf.h"

void    ft_print_d(flag_t *check_val)
{
    if (check_val->dot && !check_val->precision)
        ft_print_dd(check_val);
    else if (check_val->width && !check_val->precision)
        ft_print_dw(check_val);
    else if (check_val->precision && !check_val->width)
        ft_print_dp(check_val);
    else if (check_val->precision && check_val->width)
        ft_print_dwp(check_val);
    else
        ft_putnbr(va_arg(*check_val->arg, int), check_val);
}

void    ft_print_dw(flag_t *check_val)
{
    int i;

    i = 0;
    check_val->d = va_arg(*check_val->arg, int);
    if (check_val->d < 0 && check_val->zero)
    {
        ft_putchar('-', check_val);
        check_val->d *= -1;
        check_val->width -= 1;
    }
    if (check_val->less)
        ft_putnbr(check_val->d, check_val);
    while(i < check_val->width - (int)ft_nbrlen(check_val->d))
    {
        if (check_val->zero)
            ft_putchar('0', check_val);
        else
            ft_putchar(' ', check_val);
        i++;
    }
    if (!check_val->less)
        ft_putnbr(check_val->d, check_val);
}

void    ft_print_dp(flag_t *check_val)
{
    int i;

    i = 0;
    check_val->d = va_arg(*check_val->arg, int);
    if (check_val->d < 0)
    {
        ft_putchar('-', check_val);
        check_val->d *= -1;
    }
    if (check_val->less)
        ft_putnbr(check_val->d, check_val);
    while(i < check_val->precision - (int)ft_nbrlen(check_val->d))
    {
        ft_putchar('0', check_val);
        i++;
    }
    if (!check_val->less)
        ft_putnbr(check_val->d, check_val);
}

void    ft_print_dwp(flag_t *check_val)
{
    int i;
    int tronc;

    i = 0;
    check_val->d = va_arg(*check_val->arg, int);
    if ((int)ft_nbrlen(check_val->d) < check_val->precision)
    {
        if (check_val->d < 0)
            tronc = check_val->precision + 1;
        else
            tronc = check_val->precision;
    }
    else 
        tronc = (int)ft_nbrlen(check_val->d);
    if (check_val->less)
    {
        while(i < check_val->precision - (int)ft_nbrlen(check_val->d))
        {
            ft_putchar('0', check_val);
            i++;
        }
        ft_putnbr(check_val->d, check_val);
    }
    i = 0;
    while(i < check_val->width - tronc)
    {
        ft_putchar(' ', check_val);
        i++;
    }
    if (check_val->d < 0 && !check_val->less)
    {
        ft_putchar('-', check_val);
        check_val->d *= -1;
        check_val->width -= 1;
    }
    i = 0;
    if (!check_val->less)
    {
        while(i < check_val->precision - (int)ft_nbrlen(check_val->d))
        {
            ft_putchar('0', check_val);
            i++;
        }
        ft_putnbr(check_val->d, check_val);
    }
}

void    ft_print_dd(flag_t *check_val)
{
    int i;

    i = 0;
    check_val->d = va_arg(*check_val->arg, int);
    if (check_val->less && check_val->d)
        ft_putnbr(check_val->d, check_val);
    while(i < check_val->width - (int)ft_nbrlen(check_val->d))
    {
        if (check_val->zero)
            ft_putchar('0', check_val);
        else
            ft_putchar(' ', check_val);
        i++;
    }
    if (!check_val->less && check_val->d)
        ft_putnbr(check_val->d, check_val);
}