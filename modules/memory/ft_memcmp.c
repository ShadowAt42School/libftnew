/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 23:50:29 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 19:25:11 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int		caldiff(const void *str1, const void *str2, size_t n)
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
			if ((*(t_lintp)str1) != (*(t_lintp)str2))
				return (caldiff((t_lintp)str1, (t_lintp)str2, sizeof(t_lint)));
			str1 += (n -= sizeof(t_lint)) ? sizeof(t_lint) : sizeof(t_lint);
			str2 += sizeof(t_lint);
		}
		else if (n >= sizeof(t_int))
		{
			if (*(t_intp)str1 != *(t_intp)str2)
				return (caldiff((t_intp)str1, (t_intp)str2, sizeof(t_int)));
			str1 += (n -= sizeof(t_int)) ? sizeof(t_int) : sizeof(t_int);
			str2 += sizeof(t_int);
		}
		else
		{
			if ((*(t_chrp)str1) != (*(t_chrp)str2))
				return (caldiff((t_chrp)str1, (t_chrp)str2, sizeof(char)));
			str1 += (n -= sizeof(char)) ? sizeof(char) : sizeof(char);
			str2 += sizeof(char);
		}
	}
	return (0);
}
