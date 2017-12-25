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

static	int	ft_test(char const *s, int index)
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

double		ft_atof_printf(const char *str)
{
	double	rez1;
	double	rez2;
	int		i;

	i = 0;
	rez1 = (double)ft_atoi(str);
	while (str[i] && str[i] != '.' && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	rez2 = ft_atoi(str + i);
	while (i--)
		rez2 /= 10;
	if (rez1 < 0)
		rez1 += -rez2;
	else
		rez1 += rez2;
	return (rez1);
}
