/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:48:49 by maghayev          #+#    #+#             */
/*   Updated: 2019/10/06 23:27:38 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstaddend(t_list **alst, t_list *new_lst)
{
	t_list	*lst;

	if (!alst || !new_lst)
		return ;
	lst = *alst;
	if (!lst && (*alst = new_lst))
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new_lst;
}
