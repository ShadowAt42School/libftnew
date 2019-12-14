/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:46 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/14 06:38:00 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <stdio.h>

size_t		prepare_nullable_resp(char *buff, size_t ndigits, t_bool is_sign)
{
	size_t	counter;
	int		pos;

	counter = 0;
	pos = 0;
	if (is_sign && (pos += 1))
		*buff = '-';
	*(buff + pos++) = '0';
	if (ndigits > 0)
		*(buff + pos++) = '.';
	while (counter < ndigits && (*(buff + pos + counter) = '0'))
		counter++;
	*(buff + pos + counter) = '\0';
	return (ft_strlen(buff) - is_sign);
}

static char	*build_decimal(unsigned long long int number,
	size_t ndigits,
	char *buff)
{
	int	counter;

	*(buff + ndigits--) = '\0';
	counter = ndigits;
	while (counter >= 0)
	{
		*(buff + counter) = '0' + (number % 10);
		number /= 10;
		counter--;
	}
	*(buff + counter) += number % 10 ? 1 : 0;
	return (buff);
}

static void	build_whole(t_binary64 *fmt, char *buff, t_ullint num,
																size_t ndigit)
{
	if (ndigit == 0)
		fmt->fullpart += num % 10 ? 1 : 0;
	ft_itoa_base((buff + fmt->sign), &fmt->fullpart, 10, FALSE);
}

size_t		ft_dtos(double number, size_t ndigit, t_bool is_dot, char *buff)
{
	t_binary64				fmt;
	size_t					flen;
	double					digiter;
	double					ndecimal;
	unsigned long long int	magnitude;

	ft_binary64(number, &fmt);
	ndigit = ((int)ndigit == -1) ? 6 : ndigit;
	ndigit = (ndigit > 20) ? 20 : ndigit;
	if (!number)
		return (prepare_nullable_resp(buff, ndigit, fmt.sign));
	digiter = ft_dpow(10, ndigit);
	fmt.fullpart = fmt.actual + 0.1 / digiter;
	flen = ft_numlen(&fmt.fullpart, FALSE) + fmt.sign;
	*buff = fmt.sign ? '-' : '\0';
	if ((ndigit > 0 || (ndigit == 0 && is_dot)) && (*(buff + flen) = '.'))
		flen += 1;
	ndecimal = fmt.actual - fmt.fullpart;
	if (ndigit > 0)
	{
		magnitude = (ndecimal * digiter) + 0.5;
		build_decimal(magnitude, ndigit, buff + flen);
	}
	build_whole(&fmt, buff, (ndecimal * digiter) + 0.5, ndigit);
	return (ft_strlen(buff + fmt.sign));
}
