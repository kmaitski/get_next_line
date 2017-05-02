/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:32:55 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:42:00 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstaddn
 *  Description:  Adds a new_node to a linked list after matching the content
 *  			  parameter.
 * =============================================================================
 */
void	ft_lstaddn(t_list **list, t_list *new_node, void *content)
{
	t_list	*node;
	t_list	*store_node;

	if (!new_node)
		return ;
	node = *list;
	while (node && node->content != content)
		node = node->next;
	if (node->content == content)
	{
		store_node = node->next;
		node->next = new_node;
		new_node->next = store_node;
	}
}		/* -----  end of function ft_lstaddn  ----- */
