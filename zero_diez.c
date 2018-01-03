#include "libftprintf.h"

int ft_zero_diez_print(char *str, int pref, int suf, char c)
{
	int len;
	int nr;
	int i;

	i = 0;
	nr = 0;
	len = ft_strlen(str);
	nr += ft_putchar_f('0');
	if (c == 'x')
		nr += ft_putchar_f('x');
	else if (c == 'X')
		nr += ft_putchar_f('X');
	while (pref > ft_max(len, suf) && (pref--) - ft_max(len, suf) > 0)
		nr += ft_putchar_f('0');
	while (suf-- > len)
		nr += ft_putchar_f('0');
	while (len-- > 0)
		nr += ft_putchar_f(str[i++]);
	return (nr);
}

int ft_zero_diez(char c, int pref, int suf, va_list args)
{
	if (c == 'x')
		return (ft_zero_diez_print(ft_itoa_base_u(va_arg(args, unsigned int), 16), pref - 2, suf, c));
	else if (c == 'X')
		return (ft_zero_diez_print(ft_mari(ft_itoa_base_u(va_arg(args, unsigned int), 16)), pref - 2, suf, c));
	else
		return (ft_zero_diez_print(ft_itoa_base_u(va_arg(args, unsigned int), 8), pref - 1, suf - 1, c));
}
