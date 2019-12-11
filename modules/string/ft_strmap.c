/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:12:54 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 21:25:00 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (str - len);
}
