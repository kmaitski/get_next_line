/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:55:19 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 18:47:05 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ft_memmove
 *  Description:  Copies n characters from str2 to str1. For overlapping memory blocks, memmove() is a safer approach than ft_memcpy().
 * =====================================================================================
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	const char	*char_src;

	i = -1;
	char_dest = dest;
	char_src = src;
	if (char_dest < char_src)
		while (++i < n)
			char_dest[i] = char_src[i];
	else
		while (n--)
			char_dest[n] = char_src[n];
	return (char_dest);
}		/* -----  end of function ft_memmove  ----- */
