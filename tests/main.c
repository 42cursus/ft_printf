/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:21:40 by abelov            #+#    #+#             */
/*   Updated: 2023/12/12 19:21:46 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%015d", 0);
	fflush(stdout);
	ft_printf("\n---%x\n", 0);
	fflush(stdout);
	ft_printf("%a%x", 0);
	ft_printf("%a%x", 0);
	ft_printf("%", 0);
	return (0);
}
