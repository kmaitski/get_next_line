/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:49:34 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 18:41:59 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_memccpy
 *  Description:  Copies no more than n bytes from memory area src to memory
 *  			  area dest, stopping when the character c is found. If the
 *  			  memory areas overlap, the results are undefined.
 * =============================================================================
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*char_dest;
	const char		*char_src;

	i = 0;
	char_dest = dest;
	char_src = src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		char_dest[i] = char_src[i];
		if (char_dest[i] == c)
			return (&char_dest[++i]);
		i++;
	}
	return (NULL);
}		/* -----  end of function ft_memccpy  ----- */
