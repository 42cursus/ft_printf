/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:46:19 by abelov            #+#    #+#             */
/*   Updated: 2023/12/05 00:46:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//# if defined (__linux__)
//#  define PTRNULL "(nil)"
//# elif defined (__APPLE__)
//#  define PTRNULL "0x0"
//# endif

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);

typedef size_t	(*t_ft_print_dispatch_f)(va_list *ap);

size_t	ft_print_p(va_list *argp);
size_t	ft_print_d(va_list *argp);
size_t	ft_print_s(va_list *argp);
size_t	ft_print_x(va_list *argp);
size_t	ft_print_upperx(va_list *argp);
size_t	ft_print_u(va_list *argp);
size_t	ft_print_c(va_list *argp);
size_t	ft_print_percent(va_list *argp);

char	*ft_uitoa(unsigned int nb);
char	*ft_uitoa_base(unsigned int nb, const char *base);
char	*ft_ultoa_buf_base(unsigned long abs,
			char *buf, size_t length, const char *base);
char	*ft_print_pointer(unsigned long long nb);
#endif //FT_PRINTF_H