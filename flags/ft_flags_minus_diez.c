#include "../libftprintf.h"

int ft_flags_minus_diez(char c, int pref, int suf, va_list args, char f)
{
	if (f == 'L')
	{
		if (c == 'x')
			return (ft_minus_diez_print(ft_itoa_base_ulli(va_arg(args, ulli), 16), pref - 2, suf, c));
		if (c == 'X')
			return (ft_minus_diez_print(ft_mari(ft_itoa_base_ulli(va_arg(args, ulli), 16)), pref - 2, suf, c));
		else
			return (ft_minus_diez_print(ft_itoa_base_ulli(va_arg(args, ulli), 8), pref - 1, suf, c));
	}
	if (f == 'l')
	{
		if (c == 'x')
			return (ft_minus_diez_print(ft_itoa_base_lli(va_arg(args, lli), 16), pref - 2, suf, c));
		if (c == 'X')
			return (ft_minus_diez_print(ft_mari(ft_itoa_base_lli(va_arg(args, lli), 16)), pref - 2, suf, c));
		else
			return (ft_minus_diez_print(ft_itoa_base_lli(va_arg(args, lli), 8), pref - 1, suf, c));
	}
	if (f == 'h' || f == 'H')
	{
		if (c == 'x')
			return (ft_minus_diez_print(ft_itoa_base_us(va_arg(args, int), 16), pref - 2, suf, c));
		if (c == 'X')
			return (ft_minus_diez_print(ft_mari(ft_itoa_base_us(va_arg(args, int), 16)), pref - 2, suf, c));
		else
			return (ft_minus_diez_print(ft_itoa_base_us(va_arg(args, int), 8), pref - 1, suf - 1, c));
	}
	if (f == 's')
	{
		if (c == 'x')
			return (ft_minus_diez_print(ft_itoa_base_s((size_t)va_arg(args, ulli), 16), pref - 2, suf, c));
		if (c == 'X')
			return (ft_minus_diez_print(ft_mari(ft_itoa_base_s((size_t)va_arg(args, ulli), 16)), pref - 2, suf, c));
		else
			return (ft_minus_diez_print(ft_itoa_base_s((size_t)va_arg(args, ulli), 8), pref - 1, suf - 1, c));
	}
	if (f == 'j')
	{
		if (c == 'x')
			return (ft_minus_diez_print(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 16), pref - 2, suf, c));
		if (c == 'X')
			return (ft_minus_diez_print(ft_mari(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 16)), pref - 2, suf, c));
		else
			return (ft_minus_diez_print(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 8), pref - 1, suf - 1, c));
	}
return(0);
}
