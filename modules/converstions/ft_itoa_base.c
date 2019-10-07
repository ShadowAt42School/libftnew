/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 02:54:47 by maghayev          #+#    #+#             */
/*   Updated: 2019/10/06 22:51:55 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static char				char_rep(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

static unsigned int		operate(
	char *str,
	unsigned long long int number,
	int base
)
{
	short int	length;
	short int	index;
	char		buffer[100];

	index = 0;
	ft_bzero(buffer, 100);
	length = ft_numlen(&number, 0);
	while (number != 0 &&
		(buffer[length - 1 - index++ + 5] = char_rep(number % base)))
		number /= base;
	ft_memcpy(str, (buffer + (length - index) + 5), index);
	return (index);
}

unsigned int			ft_itoa_base(
	char *str,
	void *number,
	int base,
	t_bool is_signed
)
{
	long long int			llin;
	unsigned long long int	ullin;

	llin = 0;
	ullin = 0;
	if (is_signed)
		llin = *LLINTP(number);
	else
		ullin = *ULLINTP(number);
	if (llin == LLONG_MIN)
		ft_memcpy(str, LLINT_MIN_STR, ft_strlen(LLINT_MIN_STR));
	if (llin == LLONG_MAX && is_signed && base == 10)
		ft_memcpy(str, LLINT_MAX_STR, ft_strlen(LLINT_MAX_STR));
	else if (llin == 0 && ullin == 0 && ft_memcpy(str, "0", 1))
		return (1);
	else
	{
		if (llin < 0 && (llin *= -1) && (*str = '-'))
			str++;
		if (ullin == 0 && is_signed)
			ullin = llin;
		return (operate(str, ullin, base));
	}
	return (0);
}
