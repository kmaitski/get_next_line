/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:13:44 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:35:27 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstlast
 *  Description:  Returns the last node in a linked list pointed at by
 *  			  head_node.
 * =============================================================================
 */
t_list	*ft_lstlast(t_list *head_node)
{
	t_list	*node;

	node = head_node;
	while (node->next)
		node = node->next;
	return (node);
}		/* -----  end of function ft_lstlast  ----- */
