#include "../libftprintf.h"

ulli ft_pow_ulli(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return ((ulli)nb * ft_pow_ulli(nb , p - 1));
}

char	*ft_itoa_base_ulli(ulli nr, int base)
{
	char	*str;
	int i;

	i = 1;
	while (ft_pow_ulli(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	return (str);
}

lli ft_pow_lli(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return ((ulli)nb * ft_pow_lli(nb , p - 1));
}

char	*ft_itoa_base_lli(lli nr, int base)
{
	char	*str;
	int i;

	i = 1;
	while (ft_pow_lli(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	return (str);
}

unsigned short ft_pow_us(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return ((ulli)nb * ft_pow_us(nb , p - 1));
}

char	*ft_itoa_base_us(unsigned short nr, int base)
{
	char	*str;
	int i;

	i = 1;
	while (ft_pow_us(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	return (str);
}

size_t	ft_pow_s(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return ((ulli)nb * ft_pow_s(nb , p - 1));
}

char	*ft_itoa_base_s(size_t nr, int base)
{
	char	*str;
	int i;

	i = 1;
	while (ft_pow_s(base, i) - 1 < nr)
		i++;
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nr % base < 10 ? nr % base + '0' : nr % base + 'a' - 10);
		nr /= base;
	}
	return (str);
}

uintmax_t	ft_pow_it(unsigned int nb, int p)
{
	if (p == 0)
		return (1);
	else
		return (nb * ft_pow_it(nb , p - 1));
}

char	*ft_itoa_base_it(intmax_t nr, int base)
{
	char	*str;
	int i;
	uintmax_t nr2;

	i = 1;
	if (nr < 0)
		nr2 = 9223372036854775807 + nr + 2 + 9223372036854775807;
	else
		nr2 = nr;
	while (ft_pow_it(base, i) - 1 < nr2 && i < 30)
	{
		i++;
	}
	str = (char *)malloc(sizeof(str) * i);
	str[i] = '\0';
	while (i-- > 0 && nr2 > 0)
	{
		str[i] = (nr2 % base < 10 ? nr2 % base + '0' : nr2 % base + 'a' - 10);
		nr2 /= base;
	}
	return (&str[i + 1]);
}
