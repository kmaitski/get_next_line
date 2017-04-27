/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:57:08 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:32:25 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstmap
 *  Description:  Iterates a list lst and applies the function f to each link to
 *  			  create a “fresh” list resulting from the successive
 *  			  applications of f. If the allocation fails, the function
 *  			  returns NULL.
 * =============================================================================
 */
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_head;
	t_list	*fresh_node;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	node = lst;
	fresh_node = f(node);
	new_head = fresh_node;
	while (node->next)
	{
		node = node->next;
		fresh_node->next = f(node);
		fresh_node = fresh_node->next;
	}
	return (new_head);
}		/* -----  end of function ft_lstmap  ----- */
