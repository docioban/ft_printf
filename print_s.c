#include "libftprintf.h"

int print_s(char *str, int pref, int suf)
{
	int len;
	int nr;
	int i;

	i = 0;
	nr = 0;
	len = ft_strlen(str);
	if (suf == -1)
	{
		suf = 0;
		len = 0;
	}
	else
		len = ft_min(len, suf);
	while (pref > len && (pref--) - len - i > 0)
		nr += ft_putchar_f(' ');
	ft_putstr_f(blue_d);
	 while (len-- > 0)
	 	nr += ft_putchar_f(str[i++]);
	return (nr);
}
