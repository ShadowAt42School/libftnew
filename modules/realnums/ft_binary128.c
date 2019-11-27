/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary128.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:13:14 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/27 02:12:47 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static __uint128_t		bit_extracted(__uint128_t number, int start, int count)
{
	return ((((__uint128_t)1 << count) - 1) & (number >> (start - 1)));
}

void					ft_binary128(long double value, t_binary128 *fmt)
{
	union u_binary128	b128_rep;

	b128_rep.doubling = value;
	fmt->sign = (char)bit_extracted(b128_rep.integer, 128, 1);
	fmt->exponent = (uint16_t)bit_extracted(b128_rep.integer, 113, 15);
	fmt->mantisa = bit_extracted(b128_rep.integer, 1, 112);
	fmt->actual = ((1 + fmt->mantisa * 1.0 / ft_ldpow(2, 112)) *
										ft_ldpow(2, (fmt->exponent - 16383)));
	fmt->fullpart = (__uint128_t)fmt->actual;
}
