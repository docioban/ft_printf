/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 09:22:24 by docioban          #+#    #+#             */
/*   Updated: 2017/12/25 17:07:52 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putnbr_f(int n)
{
	int		i;
	int		nr;
	char	str[11];
	int		neg;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr_f("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
		ft_putchar_f('-');
	}
	neg = i;
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	nr = i--;
	while (i >= 0 + neg)
		ft_putchar_f(str[i--]);
	return (nr);
}

int	ft_putnbr_fu(unsigned int n)
{
	int		i;
	int		nr;
	char	str[11];

	i = 0;
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	nr = i--;
	while (i >= 0)
		ft_putchar_f(str[i--]);
	return (nr);
}
