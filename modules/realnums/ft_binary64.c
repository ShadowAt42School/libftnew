/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:13:14 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/14 05:17:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static uint64_t		bit_extracted(uint64_t number, int start, int count)
{
	return ((((uint64_t)1 << count) - 1) & (number >> (start - 1)));
}

void				ft_binary64(double value, t_binary64 *fmt)
{
	union u_binary64	b32_rep;

	b32_rep.doubling = value;
	fmt->sign = (char)bit_extracted(b32_rep.integer, 64, 1);
	fmt->exponent = (uint16_t)bit_extracted(b32_rep.integer, 53, 11);
	fmt->mantisa = bit_extracted(b32_rep.integer, 1, 52);
	fmt->actual = ((1 + fmt->mantisa * 1.0 / ft_dpow(2, 52)) *
										ft_dpow(2, (fmt->exponent - 1023)));
	fmt->fullpart = (long long int)fmt->actual;
}
