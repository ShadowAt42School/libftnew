/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 23:50:29 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/02 23:53:03 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int		calc_difference(const void *str1, const void *str2, size_t n)
{
	unsigned char *str1_tc;
	unsigned char *str2_tc;

	str1_tc = (unsigned char*)str1;
	str2_tc = (unsigned char*)str2;
	while (n)
	{
		if (*str1_tc > *str2_tc)
			return (*str1_tc - *str2_tc);
		else if (*str1_tc < *str2_tc)
			return (*str1_tc - *str2_tc);
		str1_tc++;
		str2_tc++;
		n--;
	}
	return (0);
}

int				ft_memcmp(const void *str1, const void *str2, size_t n)
{
	while (n)
	{
		if (n >= sizeof(t_lint))
		{
			if ((*(long int*)str1) != (*(long int*)str2))
				return (calc_difference(LINTP(str1), LINTP(str2), sizeof(t_lint)));
			str1 += (n -= sizeof(t_lint)) ? sizeof(t_lint) : sizeof(t_lint);
			str2 += sizeof(t_lint);
		}
		else if (n >= IS)
		{
			if (*(int*)(str1) != *(int*)(str2))
				return (calc_difference(INTP(str1), INTP(str2), IS));
			str1 += (n -= IS) ? IS : IS;
			str2 += IS;
		}
		else
		{
			if ((*(char*)str1) != (*(char*)str2))
				return (calc_difference(CHRP(str1), CHRP(str2), CS));
			str1 += (n -= CS) ? CS : CS;
			str2 += CS;
		}
	}
	return (0);
}
