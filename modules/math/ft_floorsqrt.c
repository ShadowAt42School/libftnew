/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floorsqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:47:08 by maghayev          #+#    #+#             */
/*   Updated: 2019/09/24 20:47:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_floorsqrt(int toroot)
{
	int		start;
	int		end;
	int		ans;
	int		mid;

	mid = 0;
	start = 1;
	end = toroot / 2;
	if (toroot == 0 || toroot == 1)
		return (toroot);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == toroot)
			return (mid);
		if (mid * mid < toroot)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return (ans);
}
