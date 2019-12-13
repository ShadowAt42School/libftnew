/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:31:16 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 23:41:31 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_llint		ft_strlen(const char *s)
{
	t_llint	len;

	len = 0;
	while (*s)
	{
		if (len < 0)
			return (-1);
		len++;
		s++;
	}
	return (len);
}
