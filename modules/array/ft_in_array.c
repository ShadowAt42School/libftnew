/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:26:41 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 02:48:31 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_in_array(
	const void *needle,
	const void *array,
	size_t blk_size,
	size_t size
)
{
	size_t	counter;

	counter = 0;
	while (counter < size)
	{
		if (ft_memcmp(needle, (array + (counter * blk_size)), blk_size) == 0)
			return (TRUE);
		counter++;
	}
	return (FALSE);
}
