/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:46 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/14 06:38:18 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*build_decimal(unsigned long long int number,
	size_t ndigits,
	char *buff)
{
	int		counter;

	*(buff + ndigits--) = '\0';
	counter = ndigits;
	while (counter >= 0)
	{
		*(buff + counter) = '0' + (number % 10);
		number /= 10;
		counter--;
	}
	return (buff);
}

static void	build_whole(t_binary128 *fmt, char *buff)
{
	ft_itoa_base((buff + fmt->sign), &fmt->fullpart, 10, FALSE);
}

size_t		ft_ldtos(
				long double number, size_t ndigit, t_bool is_dot, char *buff)
{
	t_binary128				fmt;
	size_t					flen;
	long double				digiter;
	long double				ndecimal;
	unsigned long long int	magnitude;

	ft_binary128(number, &fmt);
	ndigit = ((int)ndigit == -1) ? 6 : ndigit;
	ndigit = (ndigit > 20) ? 20 : ndigit;
	if (!number)
		return (ft_strlen(prepare_nullable_resp(buff, ndigit)));
	digiter = ft_ldpow(10, ndigit);
	flen = ft_numlen(&fmt.fullpart, FALSE) + fmt.sign;
	*buff = fmt.sign ? '-' : '\0';
	if ((ndigit > 0 || (ndigit == 0 && is_dot)) && (*(buff + flen) = '.'))
		flen += 1;
	ndecimal = fmt.actual - fmt.fullpart;
	if (ndigit > 0)
	{
		magnitude = (ndecimal * digiter) + 0.5;
		build_decimal(magnitude, ndigit, buff + flen--);
	}
	build_whole(&fmt, buff);
	return (ft_strlen(buff + fmt.sign));
}
