/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:00:22 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:07:23 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  *ft_memalloc
 *  Description:  Allocates and returns a “fresh” memory area. The memory 
 *  			  allocated is initialized to 0. If the allocation fails, the 
 *  			  function returns NULL.
 * =============================================================================
 */
void	*ft_memalloc(size_t size)
{
	void	*fresh;

	if (!(fresh = (void *)malloc(size)))
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}	  /* -----  end of function *ft_memalloc  ----- */

