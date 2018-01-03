#include "libftprintf.h"

int print_nr_print(char *str, int pref, int suf)
{
	int len;
	int nr;
	int i;

	i = 0;
	nr = 0;
	if (str[i] == '-')
		i++;
	len = ft_strlen(str + i);
	while (pref > ft_max(len, suf) && (pref--) - ft_max(len, suf) - i > 0)
		nr += ft_putchar_f(' ');
	if (str[0] == '-')
		nr += ft_putchar_f('-');
	while (suf > 0 && suf-- > len)
		nr += ft_putchar_f('0');
	while (len-- > 0)
		nr += ft_putchar_f(str[i++]);
	return (nr);
}

int print_p(long int p, int pref, int suf)
{
  char *str;

  str = ft_itoa_base_u(p, 16);
  return (ft_diez_print(str, pref - 2, suf, 'x'));
}

int print_x(int x, int pref, int suf)
{
  	char *str;

  	str = ft_itoa_base_u(x, 16);
  	return (print_nr_print(str, pref, suf));
}

int print_X(int x, int pref, int suf)
{
  char *str;

  str = ft_itoa_base_u(x, 16);
  str = ft_mari(str);
  return (print_nr_print(str, pref, suf));
}

int print_o(int o, int pref, int suf)
{
  char *str;

  str = ft_itoa_base_u(o, 8);
  return (print_nr_print(str, pref, suf));
}

int print_b(int b, int pref, int suf)
{
	char *str;

	str = ft_itoa_base(b, 2);
	return (print_nr_print(str, pref, suf));
}

int print_nb(int nb, int pref, int suf)
{
	char *str;

	str = ft_itoa_base(nb, 10);
	return (print_nr_print(str, pref, suf));
}

int print_nb_u(unsigned int nb, int pref, int suf)
{
	char *str;

	str = ft_itoa_base_u(nb, 10);
 	return (print_nr_print(str, pref, suf));
}

int print_nr_e(char *str, int pref)
{
	int len;
	int nr;
	int i;

	i = 0;
	nr = 0;
	len = ft_strlen(str);
	while (pref > len && (pref--) - len > 0)
		nr += ft_putchar_f(' ');
	while (len-- > 0)
		nr += ft_putchar_f(str[i++]);
	return (nr);
}

int print_le(long double nb, int pref, int suf, char c, char z)
{
	int p;
	int i;
	int nr;
	char str[8 + (suf == 0 ? 6 : suf) + (nb < 0 ? 1 : 0)];

	nr = 0;
	i = 0;
	p = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	else if (z == ' ')
		nr += ft_putchar_f(' ');
	while (nb >= 10)
	{
		p++;
		nb /= 10;
	}
	str[i++] = (int)nb + '0';
	if (suf == -1 || suf > 0)
		str[i++] = '.';
	if (suf != -1)
	{
		suf = ft_min(suf, i);
		while (suf--)
		{
			nb *= 10;
			str[i++] = (ulli)nb % 10 + '0';
		}
	}
	else
	{
		while (i < 8)
		{
			nb *= 10;
			str[i++] = (int)nb % 10 + '0';
		}
	}
	if (c == 'E')
		str[i++] = 'E';
	else
		str[i++] = 'e';
	str[i++] = '+';
	if (p < 10)
	{
		str[i++] = '0';
		str[i++] = p + '0';
	}
	else
	{
 		str[i++] = p / 10 + '0';
		str[i++] = p % 10 + '0';
	}
	str[i] = '\0';
	return (print_nr_e(str, pref));
}

int print_e(double nb, int pref, int suf, char c, char z)
{
	int p;
	int i;
	int nr;
	char str[8 + (suf == 0 ? 6 : suf) + (nb < 0 ? 1 : 0)];

	nr = 0;
	i = 0;
	p = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	else if (z == ' ')
		nr += ft_putchar_f(' ');
	while (nb >= 10)
	{
		p++;
		nb /= 10;
	}
	str[i++] = (int)nb + '0';
	if (suf == -1 || suf > 0)
		str[i++] = '.';
	if (suf != -1)
	{
		suf = ft_max(suf, 8);
		while (suf--)
		{
			nb *= 10;
			str[i++] = (ulli)nb % 10 + '0';
		}
	}
	else
	{
		while (i < 8)
		{
			nb *= 10;
			str[i++] = (int)nb % 10 + '0';
		}
	}
	if (c == 'E')
		str[i++] = 'E';
	else
		str[i++] = 'e';
	str[i++] = '+';
	if (p < 10)
	{
		str[i++] = '0';
		str[i++] = p + '0';
	}
	else
	{
 		str[i++] = p / 10 + '0';
		str[i++] = p % 10 + '0';
	}
	str[i] = '\0';
	return (print_nr_e(str, pref));
}
