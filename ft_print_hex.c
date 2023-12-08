/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:17:15 by abelov            #+#    #+#             */
/*   Updated: 2023/12/07 20:17:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_hex_buf_size(unsigned long nb)
{
	ulong		size;
	int const	hexadecimal_radix = 16;

	size = !nb;
	while (nb)
	{
		nb /= hexadecimal_radix;
		size++;
	}
	return (++size);
}

char	*ft_ultoa_hex(unsigned long nb)
{
	char				*buf;
	const char			*base = "0123456789abcdef";
	size_t				buf_size;

	buf_size = get_hex_buf_size(nb);
	buf = (char *)malloc(sizeof(char) * buf_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, buf_size);
	return (ft_ultoa_buf_base(nb, buf, buf_size, base));
}