/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:08:43 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:07:57 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strdel
 *  Description:  Takes as a parameter the address of a string that need to be 
 *  			  freed, then sets its pointer to NULL.
 * =====================================================================================
 */
void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}	  /* -----  end of function ft_strdel  ----- */
