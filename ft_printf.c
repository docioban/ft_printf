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

int		ft_switch_printf(char c, va_list args, int pref, int suf, char z)
{
	if (c == 'c' || c == 'C')
		return (ft_putchar_f(va_arg(args, int)));
	else if (c == 's')
		return (print_s(va_arg(args, char *), pref, suf));
	else if (c == 'i' || c == 'd')
		return (print_nb(va_arg(args, int), pref, suf));
	else if (c == 'p')
		return (print_p(va_arg(args, long int), pref, suf) + 2);
	else if (c == 'x')
		return (print_x(va_arg(args, int), pref, suf));
	else if (c == 'X')
		return (print_X(va_arg(args, int), pref, suf));
	else if (c == 'o' || c == 'O')
		return (print_o(va_arg(args, int), pref, suf));
	else if (c == 'u' || c == 'U')
		return (print_nb_u(va_arg(args, long int), pref, suf));
	else if (c == '%')
		return (print_procent(pref, z));
	else if (c == 'e' || c == 'E')
		return (print_e(va_arg(args, double), pref, suf, c, z));
	else if (c == 'b')
		return (print_b(va_arg(args, int), pref, suf));
	else if (c == 'n')
		*va_arg(args, int *) = put_nr;
	return (0);
}

int test(char *s, int *i)
{
	if (s[*i] == '#' || s[*i] == 'x' || s[*i] == 'X' ||
	s[*i] == 'o' || s[*i] == 'O' || s[*i] == 'c' ||
	s[*i] == 'C' || s[*i] == '%' || s[*i] == 'u' ||
	s[*i] == 'U' || s[*i] == 'p' || s[*i] == 's' ||
	s[*i] == '#' || s[*i] == ' ' || s[*i] == 'd' ||
	s[*i] == '.' || (s[*i] >= '0' && s[*i] <= '9') ||
	s[*i] == '-' || s[*i] == '+' || s[*i] == 'l' ||
	s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j' ||
	s[*i] == 'e' || s[*i] == 'E' || s[*i] == 'L' ||
	s[*i] == 'b' || s[*i] == '*' || s[*i] == 'n')
		return (1);
	return (0);
}

int ft_check(char c, char z, va_list args, int pref, int suf)
{
	if (z == '#' && (c == 'x' || c == 'X' || c == 'o'))
		return (ft_diez(c, pref, suf, args));
	else if (z == '^')
		return (ft_zero_diez(c, pref, suf, args));
	else if (z == '@')
		return (ft_minus_diez(c, pref, suf, args));
	else if (z == ')')
		return (ft_plus_diez(c, pref, suf, args));
	if (z == '0')
		return (ft_zero(c, pref, suf, args));
	if (z == '-')
		return (ft_minus(c, pref, suf, args));
	if (z == '+')
		return (ft_plus(c, pref, suf, args));
	return (0);
}

char check_flags(char *s)
{
	if (*s == 'h' && *(s + 1) == 'h')
		return ('H');
	else if (*s == 'h')
		return ('h');
	if (*s == 'l' && *(s + 1) == 'l')
		return ('L');
	else if (*s == 'l')
		return ('l');
	else if (*s == 'j')
		return ('j');
	else if (*s == 'z')
		return ('z');
	else if (*s == 'L')
		return ('E');
	return ('\0');
}

int ft_flags_check(char *s, char z, va_list args, int pref, int suf)
{
	char c;

	c = check_flags(s);
	s += 1;
	if (c <= 'Z')
		s += 1;
	if (c == 'E' || c == 'e')
		return (print_le(va_arg(args, long double), pref, suf, c, z));
	if (z == '#' && (c == 'x' || c == 'X' || c == 'o'))
		return (ft_flags_diez(*s, pref, suf, args, c));
	else if (z == '^')
		return (ft_flags_zero_diez(*s, pref, suf, args, c));
	else if (z == '@')
		return (ft_flags_minus_diez(*s, pref, suf, args, c));
	else if (z == ')')
		return (ft_flags_plus_diez(*s, pref, suf, args, c));
	if (z == '0')
		return (ft_flags_zero(*s, pref, suf, args, c));
	if (z == '-')
		return (ft_flags_minus(*s, pref, suf, args, c));
	if (z == '+')
		return (ft_flags_plus(*s, pref, suf, args, c));
	return (0);
}

int ft_function(char *s, va_list args, int pref, int suf, char z)
{
	int n;

	n = 0;
	if (z == ' ' && pref == 0 && suf == 0 && *s != '%')
		ft_putchar_f(' ');
	return (((n = ft_check(*s, z, args, pref, suf)) == 0) ? ft_switch_printf(*s, args, pref, suf, z) : n);
}

int ft_switch_flags_printf(char *s, va_list args, int pref, int suf, char z)
{
	char c;

	c = check_flags(s);
	s += 1;
	if (c <= 'Z')
		s += 1;
	if (*s == 'c' || *s == 'C')
		return (ft_putchar_f(va_arg(args, int)));
	else if (*s == 's')
		return (print_s(va_arg(args, char *), pref, suf));
	else if (*s == 'i' || *s == 'd')
		return (flags_print_nb(args, pref, suf, c));
	else if (*s == 'p')
		return (print_p(va_arg(args, long int), pref, suf) + 2);
	else if (*s == 'x')
		return (flags_print_x(args, pref, suf, c));
	else if (*s == 'X')
		return (flags_print_X(args, pref, suf, c));
	else if (*s == 'o' || *s == 'O')
		return (flags_print_o(args, pref, suf, c));
	else if (*s == 'u' || *s == 'U')
		return (flags_print_nb_u(args, pref, suf, c));
	else if (*s == '%')
		return (print_procent(pref, z));
	else if (*s == 'n')
		return (flags_put_n(args, c));
	return (0);
}

int ft_function_flags(char *s, va_list args, int pref, int suf, char z)
{
	int n;

	n = 0;
	if (z == ' ' && pref == 0 && suf == 0 && *s != '%')
		ft_putchar_f(' ');
	return (((n = ft_flags_check(s, z, args, pref, suf)) == 0) ? ft_switch_flags_printf(s, args, pref, suf, z) : n);
}

int search_convers(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '#' || s[i] == '-' || s[i] == '+'
	|| s[i] == '0' || s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	return (i);
}

void verificari(char *s, int *i, char *z)
{
	int j;

	j = 1;
	if (s[*i + search_convers(&s[*i])] == 'e' || s[*i + search_convers(&s[*i])] == 'E')
	{

		while (s[*i] == '0')
			*i += 1;
		if (s[*i] == ' ')
		{
			*z = ' ';
			*i += 1;
		}
	}
	if (s[*i] == '#' || s[*i] == ' ' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+')
	{
		*z = s[*i];
		*i += 1;
		while (s[*i] == '#' || s[*i] == ' ' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+')
		{
			if (s[*i] == ' ')
			{
				j = 1;
				while (s[*i] == ' ')
				{
					j++;
					*i += 1;
				}
			}
			else if ((s[*i] == '#' && s[*i - j] == '0') || (s[*i] == '0' && s[*i - j] == '#'))
			{
				*z = '^';
				*i += 1;
			}
			else if ((s[*i] == '#' && s[*i - j] == '-') || (s[*i] == '-' && s[*i - j] == '#'))
			{
				*z = '@';
				*i += 1;
			}
			else if ((s[*i] == '+' && s[*i - j] == '#') || (s[*i] == '#' && s[*i - j] == '+'))
			{
				*z = ')';
				*i += 1;
			}
			else if (s[*i] == '+')
			{
				*z = '+';
				*i += 1;
			}
			else
				*i += 1;
		}
	}
}

int ft_check_flags(char *s, int *i)
{
	if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'z' || s[*i] == 'j' || s[*i] == 'L')
	{
		*i += 1;
		if (s[*i] == 'h' || s[*i] == 'l')
		{
			*i += 1;
			return (2);
		}
		return (1);
	}
	return (0);
}

int		ft_switch(char *s, va_list args, int *i)
{
	int pref;
	int suf;
	char z;
	int f;

	z = '\0';
	suf = 0;
	if (test(s, i) == 0)
		return (0);
	verificari(s, i, &z);
	if (test(s, i) == 0)
		return (0);
	if (s[*i] == '*')
	{
		*i += 1;
		pref = va_arg(args, int);
	}
	else
		pref = ft_atoi(&s[*i]);
	while(s[*i] >= '0' && s[*i] <= '9')
		*i += 1;
	if (s[*i] == '.')
	{
		*i += 1;
		suf = ft_atoi(&s[*i]);
	}
	else
		suf = -1;
	while (s[*i] >= '0' && s[*i] <= '9')
		*i += 1;
	while (s[*i] == ' ' || s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+')
		*i += 1;
	if ((f = ft_check_flags(s, i)) == 0)
		return (ft_function(&s[*i], args, pref, suf, z));
	else
		return (ft_function_flags(&s[*i - f], args, pref, suf, z));
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string;
	int		i;
	int		nr;
	int		n;

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
			n = nr;
			put_nr = nr;
			nr += ft_switch(string, args, &i);
			if (test(string, &i))
				i++;
		}
	}
	return (nr);
}
