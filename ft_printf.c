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

#include <stdint.h>
#include "ft_printf.h"

int	do_print(
		register const char	*fmt,
		va_list			*argp,
		/* character output routine */
		void			(*putc)(char),
		/* default radix - for '%r' */
		int			radix)
{
	(void )radix;
	register char	c;
	c = *fmt;
	size_t	i;
	char *str;

	i = 0;
	while (c != '\0')
	{
		if (c == '%')
		{
			c = *++fmt;
			if (c == 'c') {
				(*putc)(va_arg(*argp, int));
				i++;
			}
			if (c == '%') {
				(*putc)('%');
				i++;
			}
			if (c == 'p') {
				const void *ptr = va_arg(*argp, void *);
				str = ft_print_pointer((unsigned long long int) ptr);
				if (!str) {
					free(str);
					c = *++fmt;
					continue;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if ((c == 'd') || (c == 'i')) {
				str = ft_itoa(va_arg(*argp, int));
				if (!str) {
					free(str);
					c = *++fmt;
					continue;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 'u') {
				str = ft_uitoa((unsigned int) va_arg(*argp, unsigned int));
				if (!str) {
					free(str);
					c = *++fmt;
					continue;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 'x') {
				str = ft_uitoa_base(va_arg(*argp, unsigned long),
									"0123456789abcdef");
				if (!str) {
					free(str);
					c = *++fmt;
					continue;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
				free(str);
			}
			if (c == 'X') {
				str = ft_uitoa_base(va_arg(*argp, unsigned long),
									"0123456789ABCDEF");
				if (!str) {
					free(str);
					c = *++fmt;
					continue;
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
					continue;
				}
				ft_putstr_fd(str, STDOUT_FILENO);
				i += ft_strlen(str);
			}
			if (c == '\0') {
				fmt--;
			}
		} else {
			(*putc)(c);
			i++;
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
	char		*str;
	int	count;

	if (!format || !*format)
		return (0);
	str = ft_strdup((char *)format);
	if (!str || *str == '\0')
		return (0);
	va_start(args, format);
	count = do_print(str, &args, ft_putchar, 16);
	va_end(args);
	free(str);
	return (count);
}
