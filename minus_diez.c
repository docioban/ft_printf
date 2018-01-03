#include "libftprintf.h"

int ft_puts_oxp(char c)
{
	int nr;

	nr = 0;
	nr += ft_putchar_f('0');
	if (c == 'x')
		nr += ft_putchar_f('x');
	else if (c == 'X')
		nr += ft_putchar_f('X');
	return (nr);
}

int ft_minus_diez_print(char *str, int pref, int suf, char c)
{
	int len;
	int nr;
	int i;
	int m;

	i = 0;
	nr = 0;
	len = ft_strlen(str);
	m = ft_max(len, suf);
	nr += ft_puts_oxp(c);
	while (suf-- > len)
		nr += ft_putchar_f('0');
	while (len-- > 0)
		nr += ft_putchar_f(str[i++]);
	while (pref > m && (pref--) - m > 0)
		nr += ft_putchar_f(' ');
	return (nr);
}

int ft_minus_diez(char c, int pref, int suf, va_list args)
{
	if (c == 'x')
		return (ft_minus_diez_print(ft_itoa_base_u(va_arg(args, unsigned int), 16), pref - 2, suf, c));
	else if (c == 'X')
		return (ft_minus_diez_print(ft_mari(ft_itoa_base_u(va_arg(args, unsigned int), 16)), pref - 2, suf, c));
	else
		return (ft_minus_diez_print(ft_itoa_base_u(va_arg(args, unsigned int), 8), pref - 1, suf - 1, c));
}
