#include "libftprintf.h"

int ft_print_minus_procent(int pref)
{
	int nr;

	nr = 0;
	nr += ft_putchar_f('%');
  	while ((pref) > 1 && (pref--) - 1 > 0)
		nr+=ft_putchar_f(' ');
	return (nr);
}

int print_procent(int pref, char z)
{
	int nr;

	nr = 0;
	if (z == '-')
		return (ft_print_minus_procent(pref));
  	while ((pref) > 1 && (pref--) - 1 > 0)
		nr+=ft_putchar_f(' ');
	nr += ft_putchar_f('%');
	return (nr);
}
