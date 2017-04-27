/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:47:55 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:22:11 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strncpy
 *  Description:  Copies up to n characters from the string pointed to by src to
 *  			  dest. In a case where the length of src is less than that of
 *  			  n, the remainder of dest will be padded with null bytes.
 * =============================================================================
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	c;

	c = -1;
	while (src[++c] && c < n)
		dest[c] = src[c];
	while (c < n)
		dest[c++] = '\0';
	return (dest);
}		/* -----  end of function ft_strncpy  ----- */
