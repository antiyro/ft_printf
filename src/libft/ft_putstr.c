/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:57:36 by nbouhada          #+#    #+#             */
/*   Updated: 2021/01/04 11:05:05 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, t_struc *check_val)
{
	int i;

	if (!s)
		ft_putstr("(null)", check_val);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], check_val);
		i++;
	}
}
