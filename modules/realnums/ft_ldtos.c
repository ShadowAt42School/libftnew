/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:46 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/27 02:10:15 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static char	*prepare_nullable_resp(char *buff, size_t ndigits)
{
	size_t	counter;

	counter = 0;
	*buff = '0';
	*(buff + 1) = '.';
	while (counter < ndigits && (*(buff + 2 + counter) = '0'))
		counter++;
	*(buff + counter) = '\0';
	return (buff);
}

static char	*build_decimal(__uint128_t number,
	size_t ndigits,
	char *buff)
{
	int	counter;

	*(buff + ndigits) = '\0';
	counter = ndigits - 1;
	while (counter >= 0)
	{
		*(buff + counter) = '0' + (number % 10);
		number /= 10;
		counter--;
	}
	return (buff);
}

size_t		ft_ldtos(
				long double number, size_t ndigit, t_bool is_dot, char *buff)
{
	t_binary64				fmt;
	size_t					flen;
	long double				digiter;
	long double				ndecimal;
	unsigned long long int	magnitude;

	ft_binary64(number, &fmt);
	ndigit = ((int)ndigit == -1) ? 6 : ndigit;
	ndigit = (ndigit > 20) ? 20 : ndigit;
	if (!number)
		return (ft_strlen(prepare_nullable_resp(buff, ndigit)));
	digiter = ft_dpow(10, ndigit);
	*buff = fmt.sign ? '-' : '\0';
	fmt.fullpart = fmt.actual + 0.1 / digiter;
	flen = ft_itoa_base(buff + fmt.sign, &fmt.fullpart, 10, FALSE);
	flen += fmt.sign ? 1 : 0;
	if (ndigit > 0 || (ndigit == 0 && is_dot))
		*(buff + flen) = '.';
	ndecimal = fmt.actual - fmt.fullpart;
	if (ndigit > 0)
	{
		magnitude = (ndecimal * digiter) + 0.5;
		build_decimal(magnitude, ndigit, buff + flen + 1);
	}
	return (ft_strlen(buff));
}
