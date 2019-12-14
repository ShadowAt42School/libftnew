/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldpow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:38:44 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/14 05:34:01 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

long double		ft_ldpow(long double num1, int power)
{
	long double		res;

	res = 1;
	if (power < 0)
	{
		while (power++)
			res *= num1;
		return (1.0 / res);
	}
	while (power--)
		res *= num1;
	return (res);
}
