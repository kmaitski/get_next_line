/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:45 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:18:09 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_lstnew
 *  Description:  Allocates and returns a “fresh” link. The variables content
 *  			  and content_size of the new link are initialized by copy of
 *  			  the parameters of the function. If the parameter content is
 *  			  null, the variable content is initialized to NULL and the
 *  			  variable content_size is initialized to 0 even if the
 *  			  parameter content_size isn’t. The variable next is initialized
 *  			  to NULL. If the allocation fails, the function returns NULL.
 * =============================================================================
 */
t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}		/* -----  end of function ft_lstnew  ----- */
