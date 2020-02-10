/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 22:01:30 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/09 20:53:37 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	result;
	int			sign;
	const char	*strc;

	result = 0;
	sign = 1;
	while (ft_isspace(*str, FALSE))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	strc = str;
	while (ft_isdigit(*strc) && (strc - str) < LLINT_S_L)
		result = result * 10 + *strc++ - '0';
	if ((strc - str) >= LLINT_S_L)
		return (sign > 0 ? -1 : 0);
	return (result * sign);
}
