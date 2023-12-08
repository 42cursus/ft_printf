#include "../ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%x\n", 0);
	ft_printf("---%x\n", 0);
	printf("%x\n", UINT_MAX);
	ft_printf("---%x\n", LONG_MIN);
//	printf("%x\n", LONG_MAX);
	ft_printf("---%x\n", LONG_MAX);
	return 0;
}