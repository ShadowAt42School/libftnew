/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 21:53:15 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 21:53:17 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;
	size_t	act_len;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen(src);
	if (len <= 0)
		return (src_len);
	act_len = len < src_len ? len - 1 : src_len;
	dst[act_len] = '\0';
	ft_memcpy(dst, src, act_len);
	return (src_len);
}
