/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:55:28 by maghayev          #+#    #+#             */
/*   Updated: 2019/10/03 21:46:10 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

unsigned int	ft_unumlen(unsigned long long int number)
{
	unsigned int	length;

	length = 0;
	while (number && ++length)
		number /= 10;
	return (length);
}
