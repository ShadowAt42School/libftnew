/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:21:18 by maghayev          #+#    #+#             */
/*   Updated: 2019/11/07 17:34:55 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewp(void const *content, size_t content_size)
{
	t_list *new_node;

	new_node = (t_list *)ft_memalloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (!content)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
		new_node->next = NULL;
	}
	else
	{
		if (!content)
			return (NULL);
		new_node->content = (void*)content;
		new_node->content_size = content_size;
		new_node->next = NULL;
	}
	return (new_node);
}
