/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bubble_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:53:22 by maghayev          #+#    #+#             */
/*   Updated: 2020/03/01 22:35:05 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(t_list *item1, t_list *item2)
{
	void	*tmp;

	tmp = item1->content;
	item1->content = item2->content;
	item2->content = tmp;
}

void		ft_list_bubble_sort(t_list **list, t_bool (comp)(void *, void *))
{
	t_list	*parse;
	t_list	*inner;
	t_list	*upto;

	parse = *list;
	upto = NULL;
	while (parse)
	{
		inner = *list;
		while (inner && inner->next != upto)
		{
			if (comp(inner->content, inner->next->content))
				swap(inner, inner->next);
			inner = inner->next;
		}
		upto = inner;
		parse = parse->next;
	}
}
