#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//   color
#define red "\x1B[31m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define pink "\x1B[35m"
#define blue_d "\x1B[36m"
#define white "\x1B[37m"

#define ulli unsigned long long int
#define lli long long int
#define li long int
#define ui unsigned int
#define ft_max(x, y) (x > y ? x : y)
#define ft_min(x, y) (x > y ? y : x)

int put_nr;

int ft_printf(const char *format, ...);

int     ft_putchar_f(char c);
int     ft_putstr_f(char *str);
int     ft_putnbr_f(long long int n, int nr);
int     ft_strlen(char *str);
int	    ft_atoi(const char *str);
char    *ft_itoa_base(int value, int base);
char	*ft_itoa_base_u(unsigned int nr, int base);
char    *ft_mari(char *s);
char	*ft_itoa(long long int n);

int print_s(char *s, int pref, int suf);
int print_nb(int nb, int pref, int suf);
int print_nb_u(unsigned int nb, int pref, int suf);
int print_p(long int p, int pref, int suf);
int print_x(int x, int pref, int suf);
int print_X(int x, int pref, int suf);
int print_o(int o, int pref, int suf);
int print_u(unsigned int n);
int print_procent(int pref, char z);
int ft_diez(char c, int pref, int suf, va_list args);
int ft_diez_print(char *str, int pref, int suf, char c);
int ft_zero(char c, int pref, int suf, va_list args);
int ft_zero_diez(char c, int pref, int suf, va_list args);
int ft_minus(char c, int pref, int suf, va_list args);
int ft_minus_diez(char c, int pref, int suf, va_list args);
int ft_plus(char c, int pref, int suf, va_list args);
int ft_plus_diez(char c, int pref, int suf, va_list args);
int ft_zero_diez_print(char *str, int pref, int suf, char c);
int print_zero_nr(char *s, int pref, int suf);
int ft_plus_diez_print(char *str, int pref, int suf, char c);
int print_plus_nr(char *s, int pref, int suf);
int print_minus_nr(char *s, int pref, int suf);
int ft_minus_diez_print(char *str, int pref, int suf, char c);
int print_nr_print(char *str, int pref, int suf);

int print_p(long int p, int pref, int suf);


/*   flags   */
       //   itoa_base   //
char	*ft_itoa_base_ulli(ulli nr, int base);
char	*ft_itoa_base_lli(lli nr, int base);
char	*ft_itoa_base_us(unsigned short nr, int base);
char	*ft_itoa_base_s(size_t nr, int base);
char	*ft_itoa_base_it(intmax_t nr, int base);

int flags_print_nb(va_list args, int pref, int suf, char c);
int flags_print_x(va_list, int pref, int suf, char c);
int flags_print_X(va_list, int pref, int suf, char c);
int flags_print_o(va_list, int rpef, int suf, char c);
int flags_print_nb_u(va_list args, int pref, int suf, char c);
int ft_flags_minus(char c, int pref, int suf, va_list args, char f);
int ft_flags_zero_diez(char c, int pref, int suf, va_list args, char f);
int ft_flags_plus(char c, int pref, int suf, va_list args, char f);
int ft_flags_zero(char c, int pref, int suf, va_list args, char f);
int ft_flags_diez(char c, int pref, int suf, va_list args, char f);
int ft_flags_plus_diez(char c, int pref, int suf, va_list args, char f);
int ft_flags_minus_diez(char c, int pref, int suf, va_list args, char f);
int ft_flags_zero_diez(char c, int pref, int suf, va_list args, char f);


/*    bonus   */
int print_e(double nb, int pref, int suf, char c, char z);
int print_le(long double nb, int pref, int suf, char c, char z);
int print_b(int b, int pref, int suf);
int flags_put_n(va_list args, char c);

#endif
