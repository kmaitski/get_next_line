/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:52:28 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 18:37:00 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_bzero
 *  Description:  Place n zero-valued bytes in the area pointed to by s.
 * =============================================================================
 */
void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = 0;
}		/* -----  end of function ft_bzero  ----- */
