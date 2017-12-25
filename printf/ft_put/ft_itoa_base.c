/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 11:38:58 by docioban          #+#    #+#             */
/*   Updated: 2017/12/24 15:50:30 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_pow(int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return (nb * ft_pow(nb , p - 1));
}

char	*ft_itoa_base(int nr, int base)
{
	char	*str;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	if (nr < 0)
	{
		if (base == 10)
			nr *= -1;
		neg = 1;
	}
	while (ft_pow(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i + neg] = '\0';
	while (i-- > 0)
	{
		str[i - neg] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
