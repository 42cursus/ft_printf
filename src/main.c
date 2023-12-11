#include "../ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%015d", 0);
	fflush(stdout);
	ft_printf("\n---%x\n", 0);
	printf("%", 0);
	fflush(stdout);
	ft_printf("%", 0);
//	printf("\np: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//	fflush(stdout);
//	ft_printf("\nft: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//	printf("%x\n", UINT_MAX);
//	printf("\nptr p:---%p\n", (void *)0);
//	ft_printf("ptr ft:---%p\n", (void *)0);
//	printf("ptr p:---%p\n", (void *)printf);
//	ft_printf("ptr ft:---%p\n", (void *)printf);
//	printf("p:---%llx\n", 9223372036854775807LL);
//	ft_printf("ft:---%x\n", 9223372036854775807LL);
//	printf("p:---%x\n", 0);
//	ft_printf("ft:---%x\n", 0);
//	printf("%lu\n", LONG_MAX);
//	ft_printf("---%x\n", LONG_MAX);
//	ft_printf("-\t--%x\n", LONG_MAX);
	return 0;
}