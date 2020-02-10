/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:31:16 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/12 22:42:33 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (len == ULONG_MAX)
			return (-1);
		len++;
		s++;
	}
	return (len);
}
