/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnumlen_inplace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:51:40 by maghayev          #+#    #+#             */
/*   Updated: 2019/09/29 21:56:26 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_strnumlen_inplace(const char **str)
{
	int		len;

	len = 0;
	while (ft_isdigit(**str))
	{
		len++;
		(*str)++;
	}
	return (len);
}
