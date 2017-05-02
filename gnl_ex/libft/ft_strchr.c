/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:36:41 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:31:22 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strchr
 *  Description:  Searches for the first occurrence of the character c (an
 *  		 	  unsigned char) in the string pointed to by the argument str.
 * =============================================================================
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char*)str);
	return (NULL);
}		/* -----  end of function ft_strchr  ----- */
