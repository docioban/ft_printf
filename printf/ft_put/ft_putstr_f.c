/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 09:26:15 by docioban          #+#    #+#             */
/*   Updated: 2017/12/25 17:07:46 by docioban         ###   ########.fr       */
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

int	print_s(double nr)
{
	if (nr < 0)
		nr *= -1;
	double	nr1;
	int		n;

	n = 0;
	nr1 = nr;
	if (nr1 - (int)nr1 > 0)
	{
		while ((nr1 -= (int)nr1) != 0)
		{
			n *= 10;
			n += nr1;
			nr1 *= 10;
		}
	}
	else
		return ((int)nr);
	return (n);
}

int	ft_putstr_fm(char *str, double nr, char c)
{
	int i;
	int j;

	nr = print_s(nr);
	j = nr;
	i = 0;
	while (nr--)
		ft_putchar_f(c);
	while (str[i] != '\0')
	{
		ft_putchar_f(str[i]);
		i++;
	}
	return (i + j);
}
