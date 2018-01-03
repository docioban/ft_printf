#include "../libftprintf.h"

int ft_flags_minus(char c, int pref, int suf, va_list args, char f)
{
	if (f == 'L')
	{
		if (c == 'd' || c == 'i')
			return (print_minus_nr(ft_itoa_base_ulli(va_arg(args, ulli), 10), pref, suf));
		else if (c == 'u')
			return (print_minus_nr(ft_itoa_base_ulli(va_arg(args, ulli), 10), pref, suf));
		else if (c == 'p')
			return (print_minus_nr(ft_itoa_base_ulli(va_arg(args, ulli), 10), pref, suf));
		else if (c == 'x')
			return (print_minus_nr(ft_itoa_base_ulli(va_arg(args, ulli), 16), pref, suf));
		else if (c == 'X')
			return (print_minus_nr(ft_mari(ft_itoa_base_ulli(va_arg(args, ulli), 16)), pref, suf));
		else if (c == 'o' || c == 'O')
			return (print_minus_nr(ft_itoa_base_ulli(va_arg(args, ulli), 8), pref, suf));
	}
	if (f == 'l')
	{
		if (c == 'd' || c == 'i')
			return (print_minus_nr(ft_itoa_base_lli(va_arg(args, lli), 10), pref, suf));
		else if (c == 'u')
			return (print_minus_nr(ft_itoa_base_lli(va_arg(args, lli), 10), pref, suf));
		else if (c == 'p')
			return (print_minus_nr(ft_itoa_base_lli(va_arg(args, lli), 10), pref, suf));
		else if (c == 'x')
			return (print_minus_nr(ft_itoa_base_lli(va_arg(args, lli), 16), pref, suf));
		else if (c == 'X')
			return (print_minus_nr(ft_mari(ft_itoa_base_lli(va_arg(args, lli), 16)), pref, suf));
		else if (c == 'o' || c == 'O')
			return (print_minus_nr(ft_itoa_base_lli(va_arg(args, lli), 8), pref, suf));
	}
	if (f == 'h' || f == 'H')
	{
		if (c == 'd' || c == 'i')
			return (print_minus_nr(ft_itoa_base_us((unsigned short)va_arg(args, int), 10), pref, suf));
		else if (c == 'u')
			return (print_minus_nr(ft_itoa_base_us((unsigned short)va_arg(args, int), 10), pref, suf));
		else if (c == 'p')
			return (print_minus_nr(ft_itoa_base_us((unsigned short)va_arg(args, int), 10), pref, suf));
		else if (c == 'x')
			return (print_minus_nr(ft_itoa_base_us((unsigned short)va_arg(args, int), 16), pref, suf));
		else if (c == 'X')
			return (print_minus_nr(ft_mari(ft_itoa_base_us((unsigned short)va_arg(args, int), 16)), pref, suf));
		else if (c == 'o' || c == 'O')
			return (print_minus_nr(ft_itoa_base_us((unsigned short)va_arg(args, int), 8), pref, suf));
	}
	if (f == 's')
	{
		if (c == 'd' || c == 'i')
			return (print_minus_nr(ft_itoa_base_s((size_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'u')
			return (print_minus_nr(ft_itoa_base_s((size_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'p')
			return (print_minus_nr(ft_itoa_base_s((size_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'x')
			return (print_minus_nr(ft_itoa_base_s((size_t)va_arg(args, ulli), 16), pref, suf));
		else if (c == 'X')
			return (print_minus_nr(ft_mari(ft_itoa_base_s((size_t)va_arg(args, ulli), 16)), pref, suf));
		else if (c == 'o' || c == 'O')
			return (print_minus_nr(ft_itoa_base_s((size_t)va_arg(args, ulli), 8), pref, suf));
	}
	if (f == 'j')
	{
		if (c == 'd' || c == 'i')
			return (print_minus_nr(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'u')
			return (print_minus_nr(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'p')
			return (print_minus_nr(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 10), pref, suf));
		else if (c == 'x')
			return (print_minus_nr(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 16), pref, suf));
		else if (c == 'X')
			return (print_minus_nr(ft_mari(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 16)), pref, suf));
		else if (c == 'o' || c == 'O')
			return (print_minus_nr(ft_itoa_base_it((intmax_t)va_arg(args, ulli), 8), pref, suf));
	}
	return (0);
}
