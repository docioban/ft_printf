#include "../../libftprintf.h"

int flags_print_nb(va_list args, int pref, int suf, char c)
{
	char *str;

	str = NULL;
	if (c == 'L')
		str = ft_itoa_base_ulli(va_arg(args, ulli), 10);
	else if (c == 'l')
		str = ft_itoa_base_lli(va_arg(args, lli), 10);
	else if (c == 'h' || c == 'H')
		str = ft_itoa_base_us((unsigned short)va_arg(args, int), 10);
	else if (c == 'z')
		str = ft_itoa_base_s((size_t)va_arg(args, ulli), 10);
	else if(c == 'j')
		str = ft_itoa_base_it(va_arg(args, intmax_t), 10);

	return (print_nr_print(str, pref, suf));
}

int flags_print_x(va_list args, int pref, int suf, char c)
{
	char *str;

	str = NULL;
	if (c == 'L')
		str = ft_itoa_base_ulli(va_arg(args, ulli), 16);
	else if (c == 'l')
		str = ft_itoa_base_lli(va_arg(args, lli), 16);
	else if (c == 'h' || c == 'H')
		str = ft_itoa_base_us((unsigned short)va_arg(args, int), 16);
	else if (c == 'z')
		str = ft_itoa_base_s((size_t)va_arg(args, ulli), 16);
	else if(c == 'j')
		 str =ft_itoa_base_it((va_arg(args, intmax_t)), 16);
	return (print_nr_print(str, pref, suf));
}

int flags_print_X(va_list args, int pref, int suf, char c)
{
	char *str;

	str = NULL;
	if (c == 'L')
		str = ft_mari(ft_itoa_base_ulli(va_arg(args, ulli), 16));
	else if (c == 'l')
		str = ft_mari(ft_itoa_base_lli(va_arg(args, lli), 16));
	else if (c == 'h' || c == 'H')
		str = ft_mari(ft_itoa_base_us((unsigned short)va_arg(args, int), 16));
	else if (c == 'z')
		str = ft_mari(ft_itoa_base_s((size_t)va_arg(args, ulli), 16));
	else if(c == 'j')
		str =ft_mari(ft_itoa_base_it((intmax_t)va_arg(args, lli), 16));
	return (print_nr_print(str, pref, suf));
}

int flags_print_o(va_list args, int pref, int suf, char c)
{
	char *str;

	str = NULL;
	if (c == 'L')
		str = ft_itoa_base_ulli(va_arg(args, ulli), 8);
	else if (c == 'l')
		str = ft_itoa_base_lli(va_arg(args, lli), 8);
	else if (c == 'h' || c == 'H')
		str = ft_itoa_base_us((unsigned short)va_arg(args, int), 8);
	else if (c == 'z')
		str = ft_itoa_base_s((size_t)va_arg(args, ulli), 8);
		else if(c == 'j')
			str =ft_itoa_base_it((intmax_t)va_arg(args, lli), 8);
	return (print_nr_print(str, pref, suf));
}

int flags_print_nb_u(va_list args, int pref, int suf, char c)
{
	char *str;

	str = NULL;
	if (c == 'L')
		str = ft_itoa_base_ulli(va_arg(args, ulli), 10);
	else if (c == 'l')
		str = ft_itoa_base_lli(va_arg(args, lli), 10);
	else if (c == 'h' || c == 'H')
		str = ft_itoa_base_us((unsigned short)va_arg(args, int), 10);
	else if (c == 'z')
		str = ft_itoa_base_s((size_t)va_arg(args, ulli), 10);
	else if(c == 'j')
		str = ft_itoa_base_it((intmax_t)va_arg(args, lli), 10);
	return (print_nr_print(str, pref, suf));
}

int flags_put_n(va_list args, char c)
{
	if (c == 'L')
		*va_arg(args, ulli *) = put_nr;
	else if (c == 'l')
		*va_arg(args, lli *) = put_nr;
	else if (c == 'h')
		*va_arg(args, short int *) = (short int)put_nr;
	else if (c == 'H')
		*va_arg(args, signed char *) = (signed char)put_nr;
	else if (c == 'l')
		*va_arg(args, long int *) = (long int)put_nr;
	else if (c == 'L')
		*va_arg(args, lli *) = (lli)put_nr;
	else if (c == 'j')
		*va_arg(args, intmax_t *) = (intmax_t)put_nr;
	else if (c == 'z')
		*va_arg(args, size_t *) = (size_t)put_nr;
	return (0);
}
