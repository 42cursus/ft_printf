/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:46:08 by abelov            #+#    #+#             */
/*   Updated: 2023/12/05 00:46:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_print(
		register const char	*fmt,
		va_list			*argp,
		/* character output routine */
		void			(*putc)(char),
		int			radix)		/* default radix - for '%r' */
{
	(void )radix;
	register char	c;
	c = *fmt;
	size_t	i;
	char *str;

	i = 0;
	while (c != '\0')
	{
		if (c != '%') {
			(*putc)(c);
			i++;
		} else {
			c = *++fmt;
			if (c == 'c') {
				(*putc)(va_arg(*argp, int));
				i++;
			}
			if (c == '%') {
				(*putc)('%');
				i++;
			}
			if (c == 'p')
				i += printf("%p", va_arg(*argp, void *));
			if ((c == 'd') || (c == 'i')) {
				str = ft_itoa(va_arg(*argp, int));
				if (!str) {
					free(str);
					c = *++fmt;
					continue ;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 'u'){
				str = ft_uitoa((unsigned int)va_arg(*argp, unsigned int));
				if (!str) {
					free(str);
					c = *++fmt;
					continue ;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 'x'){

				ulong l = va_arg(*argp, unsigned long);
				str = ft_ultoa_hex(l);
				if (!str) {
					free(str);
					c = *++fmt;
					continue ;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 's') {
				str = va_arg(*argp, char *);
				if (!str) {
					str = "(null)";
					ft_putstr_fd(str, STDOUT_FILENO);
					i += ft_strlen(str);
					c = *++fmt;
					continue ;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
			}
		}
		c = *++fmt;
	}
	return (i);
}

void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int	i;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	i = do_print(format, &args, ft_putchar, 16);
	va_end(args);
	return (i);
}


//int main()
//{
//	ft_printf("%c", '0');
//	printf("\n");
//	printf("\n--%d",ft_printf("%s", "Hey Ho!"));
//	return (0);
//}