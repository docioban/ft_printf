#include "libftprintf.h"

int print_plus_nr(char *s, int pref, int suf)
{
	int len;
	int nr;
	int i;

	i = 0;
	nr = 0;
	len = ft_strlen(s);
	while (pref > ft_max(len, suf) && (pref--) - ft_max(len, suf) > 0)
		nr += ft_putchar_f(' ');
	while (suf-- > len)
		nr += ft_putchar_f('0');
	while (len-- > 0)
		nr += ft_putchar_f(s[i++]);
	return (nr);
}

int print_plus_x(char *s, int pref, int suf)
{
	return (print_plus_nr(s, pref, suf));
}

int print_plus_X(char *s, int pref, int suf)
{
	return (print_plus_nr(s, pref, suf));
}

int print_plus_o(char *s, int pref, int suf)
{
	return (print_plus_nr(s, pref, suf));
}

int print_plus_u(char *s, int pref, int suf)
{
	return (print_plus_nr(s, pref, suf));
}

int print_plus_p(char *s, int pref, int suf)
{
	return (print_plus_nr(s, pref, suf));
}

int ft_plus(char c, int pref, int suf, va_list args)
{
	if (c == 'd' || c == 'i')
		return (print_plus_nr(ft_itoa_base(va_arg(args, int), 10), pref, suf));
	else if (c == 'x')
		return (print_plus_x(ft_itoa_base_u(va_arg(args, unsigned int), 16), pref, suf));
	else if (c == 'X')
		return (print_plus_X(ft_mari(ft_itoa_base_u(va_arg(args, unsigned int), 16)), pref, suf));
	else if (c == 'o' || c == '0')
		return (print_plus_o(ft_itoa_base_u(va_arg(args, unsigned int), 8), pref, suf));
	else if (c == 'u')
		return (print_plus_u(ft_itoa_base_u(va_arg(args, unsigned int), 10), pref, suf));
	else if (c == 'p')
		return (print_plus_p(ft_itoa_base_u(va_arg(args, long int), 10), pref, suf));
	else
		return (0);
}
