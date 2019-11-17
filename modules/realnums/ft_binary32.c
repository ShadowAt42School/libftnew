/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:59:13 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/16 19:48:04 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <stdio.h>

void	ft_binary32(float value, t_binary32 *fmt)
{
	union u_binary32	b32_rep;

	b32_rep.floating = value;

	unsigned int temp = (int)b32_rep.floating;
	for( unsigned long i = 0; i < sizeof(float) * 8; i++ ) {
		printf("%d", temp & 0x1);
		temp = temp >> 1;
	}
	if (value < 0)
	{
		fmt->sign = 1;
	}
}
