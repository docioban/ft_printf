/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:39:22 by docioban          #+#    #+#             */
/*   Updated: 2017/12/25 17:10:23 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_switch_printf(char c, va_list args, double nr)
{
	nr = 0;
	if (c == 'c' || c == 'C')
		return (ft_putchar_f(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_f(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_f(va_arg(args, int)));
//	else if (c == 'p')
//		return (ft_putstr_f(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_putstr_fm(ft_mici(ft_itoa_base(va_arg(args, int), 16)), nr, ' '));
	else if (c == 'X')
		return (ft_putstr_f(ft_mari(ft_itoa_base(va_arg(args, int), 16))));
	else if (c == 'o' || c == 'O')
		return (ft_putstr_f(ft_mici(ft_itoa_base(va_arg(args, int), 8))));
	else if (c == 'u' || c == 'U')
		return (ft_putnbr_fu(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar_f('%'));
	return (0);
}

int		ft_switch(char *s, va_list args)
{
	double	nr;
	int		i;

	i = 0;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		i++;
	nr = ft_atof_printf(s);
	return (ft_switch_printf(s[i], args, nr));
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string;
	int		i;
	int		nr;
//	int		nr1;

	i = 0;
	nr = 0;
	va_start(args, format);
	string = (char *)format;
	while(string[i] != '\0')
	{
		while (string[i] != '%' && string[i] != '\0')
		{
			nr += ft_putchar_f(string[i]);
			i++;
		}
		if (string[i] != '\0')
		{
			i++;
	//		if (string[i] == ' ' || string[i] == '#' || string[i] == '+' || string[i] == '-' || string[i] == '0')
	//			i++;
	//		nr += ft_switch_printf(string[i], args);
			nr += ft_switch(&string[i], args);
			//nr1 = nr;
		//	nr += ft_switch(&string[i], args);
			//i--;
		//	i += nr - nr1;
			i++;
		}
	}
	return (nr);
}
