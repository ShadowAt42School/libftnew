/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:59:03 by maghayev          #+#    #+#             */
/*   Updated: 2019/10/02 21:21:42 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_strdelim(char **dest, const char *s1, char delim)
{
	int		len;

	len = ft_strlendelim(s1, delim);
	*dest = ft_strnew(len);
	if (dest == NULL)
		return (0);
	ft_memcpy(*dest, s1, len);
	return (len);
}
