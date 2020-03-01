/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:05:20 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/29 19:56:01 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ullint		ft_umax(t_ullint chalenger, t_ullint champion)
{
	return (chalenger > champion ? chalenger : champion);
}
