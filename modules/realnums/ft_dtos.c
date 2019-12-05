/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:46 by maghayev          #+#    #+#             */
/*   Updated: 2019/12/03 22:46:47 by maghayev         ###   ########.fr       */
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
	*(buff + counter + 2) = '\0';
	return (buff);
}

static char	*build_decimal(unsigned long long int number,
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
		return (ft_strlen(prepare_nullable_resp(buff, ndigit)));
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
	ft_itoa_base(buff + fmt.sign, &fmt.fullpart, 10, FALSE);
	return (ft_strlen(buff + fmt.sign));
}
