/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:38:24 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 16:30:29 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_memdel
 *  Description:  Takes as a parameter the address of a memory area that needs 
 *  			  to be freed, then puts the pointer to NULL.
 * =============================================================================
 */

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}	  /* -----  end of function ft_memdel  ----- */
