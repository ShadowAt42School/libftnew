/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:46:35 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 22:59:05 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const char	*begin;
	const char	*pattern;
	int			n_cpy;

	if (n == 0)
		return (!*little ? (char*)big : NULL);
	if (*big == *little && *big == '\0')
		return ((char *)big);
	while (*big && n > 0)
	{
		n_cpy = n;
		begin = big;
		pattern = little;
		while (*pattern && *big && *pattern == *big && n_cpy > 0)
		{
			pattern++;
			big++;
			n_cpy--;
		}
		if (!*pattern)
			return ((char *)begin);
		big = begin + 1;
		n--;
	}
	return (NULL);
}
