/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:59:12 by docioban          #+#    #+#             */
/*   Updated: 2017/12/24 15:14:52 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int		ft_itoa_size(int value, int base)
{
	if (base == 10 && value < 0)
		return (ft_itoa_size(-value, base) + 1);
	if (value < 0)
		value = -value;
	if (value >= base)
		return (ft_itoa_size(value / base, base) + 1);
	else
		return (1);
}

void	ft_itoa_base_calcule(int value, int base, char *str)
{
	int i;

	i = 0;
	if (base == 10 && value < 0)
		str[0] = '-';
	if (value < 0)
		value = -value;
	if (value >= base)
	{
		ft_itoa_base_calcule(value / base, base, str);
		ft_itoa_base_calcule(value % base, base, str);
	}
	else
	{
		if (value >= 10)
			value = value + 39;
		while (str[i] != '\0')
			i++;
		str[i] = value + '0';
	}
}

char	*ft_itoa_base(int value, int base)
{
	int		length;
	char	*str;

	if (base >= 2 && base <= 16)
	{
		length = ft_itoa_size(value, base);
		str = (char*)malloc(sizeof(char) * (length + 1));
		ft_itoa_base_calcule(value, base, str);
		str[length] = '\0';
	}
	else
		return (0);
	return (str);
}

unsigned int ft_pow_u(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return (nb * ft_pow_u(nb , p - 1));
}

char	*ft_itoa_base_u(unsigned int nr, int base)
{
	char	*str;
	int i;

	i = 1;
	while (ft_pow_u(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	return (str);
}

int	ft_test(char const *s, int index)
{
	int n;

	n = 0;
	while (s[index] >= '0' && s[index] <= '9')
	{
		n *= 10;
		n += (int)s[index] - '0';
		index++;
	}
	return (n);
}

int			ft_atoi(const char *str)
{
	int n;
	int i;
	int neg;
	int j;

	i = 0;
	neg = -1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	if (j - i > 10)
		return (neg);
	n = ft_test(str, i);
	if (neg)
		return (n);
	return (-n);
}
