/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:54:03 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:27:34 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstiter
 *  Description:  Iterates the list lst and applies the function f to each link.
 * =============================================================================
 */
void	ft_lstiter(t_list *lst, void (*f)(t_list *elm))
{
	t_list	*node;

	if (!f)
		return ;
	node = lst;
	while (node)
	{
		f(node);
		node = node->next;
	}
}		/* -----  end of function ft_lstiter  ----- */
