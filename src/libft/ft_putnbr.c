/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:40:29 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/13 16:16:06 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, flag_t *check_val)
{
	if (n < 0)
	{
		ft_putchar('-', check_val);
		n = -n;
		if (n == -2147483648)
		{
			ft_putchar('2', check_val);
			n = 147483648;
		}
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, check_val);
		n = n % 10;
	}
	ft_putchar(n + '0', check_val);
}
