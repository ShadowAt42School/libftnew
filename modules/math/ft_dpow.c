/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:38:44 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/27 01:40:58 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_dpow(double num1, int power)
{
	double		res;

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
