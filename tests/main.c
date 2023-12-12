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

/*
 * fflush(stdout);
 * printf("%015d", 0);
 * fflush(stdout);
 * */
int	main(void)
{
	ft_printf("\n---%x\n", 0);
	ft_printf("\n%a%x", 0);
	ft_printf("\n%x", 0);
	ft_printf("\n%", 0);
	return (0);
}
