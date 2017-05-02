/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:30 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:36:34 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstsize
 *  Description:  Counts the nodes in a linked list pointed to by head_node.
 * =============================================================================
 */
unsigned int	ft_lstsize(t_list *head_node)
{
	unsigned int	count;
	t_list			*node;

	count = 0;
	node = head_node;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}		/* -----  end of function ft_lstsize  ----- */
