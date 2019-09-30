/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnumlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:51:40 by maghayev          #+#    #+#             */
/*   Updated: 2019/09/29 21:53:27 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_strnumlen(char *str)
{
	int		len;

	len = 0;
	while (IS_DIGIT(*str))
	{
		len++;
		str++;
	}
	return (len);
}
