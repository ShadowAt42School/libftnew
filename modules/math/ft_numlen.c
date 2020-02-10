/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:55:28 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 19:21:20 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		operate(
	long long int *llin,
	unsigned long long int *ullin,
	unsigned int *length
)
{
	while ((*llin != 0 || *ullin != 0) && (++(*length)))
	{
		if (*llin != 0)
			*llin /= 10;
		else
			*ullin /= 10;
	}
}

unsigned int	ft_numlen(void *number, t_bool is_signed)
{
	unsigned int			length;
	long long int			llin;
	unsigned long long int	ullin;

	length = 0;
	llin = 0;
	ullin = 0;
	if (is_signed)
		llin = *(t_llintp)(number);
	else
		ullin = *(t_ullintp)(number);
	if (llin == LLONG_MIN || llin == LLONG_MAX)
		return (length = 20);
	if (llin == 0 && ullin == 0)
		return (1);
	if (llin < 0)
		llin *= -1;
	operate(&llin, &ullin, &length);
	return (length);
}
