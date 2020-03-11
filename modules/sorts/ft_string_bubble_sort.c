/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bubble_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:53:22 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/10 23:35:29 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void		ft_string_bubble_sort(char ***strings, size_t count,
												t_bool (comp)(char *, char *))
{
	size_t	outer_index;
	size_t	inner_index;
	char	**arr;

	arr = *strings;
	outer_index = 0;
	while (outer_index < count)
	{
		inner_index = 0;
		while (inner_index < count - outer_index - 1)
		{
			if (comp(arr[inner_index], arr[inner_index + 1]))
				swap(arr + inner_index, arr + inner_index + 1);
			inner_index++;
		}
		outer_index++;
	}
}
