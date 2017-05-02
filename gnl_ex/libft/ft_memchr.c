/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:53:22 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:09:59 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_memchr
 *  Description:  Searches for the first occurrence of the character c (an
 *  			  unsigned char) in the first n bytes of the string pointed to
 *  			  by the argument str.
 * =============================================================================
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*char_str;

	char_str = str;
	while (n--)
	{
		if (*char_str == (unsigned char)c)
			return ((void*)char_str);
		char_str++;
	}
	return (NULL);
}		/* -----  end of function ft_memchr  ----- */
