/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:05:07 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:20:56 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstdelone
 *  Description:  Takes as a parameter a link’s pointer address and frees the
 *  			  memory of the link’s content using the function del given as a
 *  			  parameter, then frees the link’s memory. The memory of next
 *  			  musnt not be freed under any circumstance. Finally, the
 *  			  pointer to the link that was just freed must be set to NULL.
 * =============================================================================
 */
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (!alst || !del)
		return ;
	node = *alst;
	del(node->content, node->content_size);
	*alst = NULL;
}		/* -----  end of function ft_lstdelone  ----- */
