#include "../libftprintf.h"
#include <stdio.h>

int main()
{
	double n = 3.0;
	int x;
	int y;
	int a = 0;
	a = ft_printf("%20.20sred\n", "3.14");
	int b = printf("%20.20sred\n", "3.14");
	printf("%d   %d\n", x, y);
	printf("%d    %d\n", a, b);
}
