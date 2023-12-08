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
# include "libft/libft.h"
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

char	*ft_uitoa(unsigned int nb);
char	*ft_ultoa_hex(unsigned long nb);
char	*ft_ultoa_buf_base(unsigned long abs,
						   char *buf, size_t length, const char *base);
#endif //FT_PRINTF_H