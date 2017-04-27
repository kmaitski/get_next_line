/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:56:14 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:33:40 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strcat
 *  Description:  Appends the string pointed to by src to the end of the string
 *  			  pointed to by dest.
 * =============================================================================
 */
char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;

	i = ft_strlen(dest);
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}		/* -----  end of function ft_strcat  ----- */
