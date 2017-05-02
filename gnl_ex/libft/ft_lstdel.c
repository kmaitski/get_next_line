/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:35:30 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:13:44 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstdel
 *  Description:  Takes as a parameter the adress of a pointer to a link and
 *  			  frees the memory of this link and every successors of that
 *  			  link. Finally the pointer to the link that was just freed must
 *  			  be set to NULL.
 * =============================================================================
 */
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next_node;

	if (!del)
		return ;
	node = *alst;
	while (node)
	{
		next_node = node->next;
		del(node->content, node->content_size);
		free(node);
		node = next_node;
	}
	*alst = NULL;
}		/* -----  end of function ft_lstdel  ----- */
