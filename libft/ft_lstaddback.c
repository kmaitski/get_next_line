/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:57:47 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:34:09 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstaddback
 *  Description:  Adds a new_node to the end of a linked list list.
 * =============================================================================
 */
void	ft_lstaddback(t_list **list, t_list *new_node)
{
	t_list	*node;

	if (!new_node)
		return ;
	node = *list;
	if (!node)
	{
		node = new_node;
		new_node->next = NULL;
	}
	else
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
}		/* -----  end of function ft_lstaddback  ----- */
