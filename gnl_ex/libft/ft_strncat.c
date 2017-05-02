/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:33:14 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:35:52 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strncat
 *  Description:  Appends the string pointed to by src to the end of the string
 *  			  pointed to by dest up to n characters long.
 * =============================================================================
 */
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	size_t			j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}		/* -----  end of function ft_strncat  ----- */
