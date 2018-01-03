/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 09:26:15 by docioban          #+#    #+#             */
/*   Updated: 2017/12/27 12:15:33 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putchar_f(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_f(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_f(str[i]);
		i++;
	}
	return (i);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_f(long long int n, int nr)
{
	if (n < 0)
	{
		nr += ft_putchar_f('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_f(n / 10, nr);
		ft_putnbr_f(n % 10, nr);
	}
	else
		nr += ft_putchar_f(n + '0');
	return (nr);
}
