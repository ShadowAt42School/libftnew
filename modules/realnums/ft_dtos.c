/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:46 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/24 22:30:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <stdio.h>
#include <math.h>

char	*ft_dtos(double value, unsigned int precision)
{
	t_binary64		b64;
	t_double_s		double_s;
	unsigned int	counter;

	precision = 0;
	counter = 0;
	ft_bzero(&b64, sizeof(t_binary64));
	ft_bzero(&double_s, sizeof(t_double_s));
	ft_binary64(value, &b64);
	double_s.intrep = (int64_t)b64.actual;
	ft_itoa_base((char*)double_s.intreps, &double_s.intrep, 10, TRUE);
	double_s.afterdot = b64.actual - (double)double_s.intrep;
	return ("");
}
