#include "libftprintf.h"
#include <stdio.h>

int main()
{
	int a;
	int b;

	a = printf("%x\n", 200);
	b = ft_printf("%x\n", 200);



	printf("%d     %d", a, b);
}
