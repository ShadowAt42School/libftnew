/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:10:38 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/10 21:45:30 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (ft_strsub(s, start, len));
}
