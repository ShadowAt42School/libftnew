/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:38:24 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/04 15:39:50 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	ft_bzero((void*)s, ft_strlen(s));
}
