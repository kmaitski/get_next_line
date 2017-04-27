/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:55:51 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 18:32:23 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_memset
 *  Description:  Copies the character c (an unsigned char) to the first n
 *  			  characters of the string pointed to, by the argument str.
 * =============================================================================
 */
void	*ft_memset(void *str, int c, size_t n)
{
	char			*char_str;
	unsigned int	i;

	char_str = str;
	i = 0;
	while (n--)
		char_str[i++] = c;
	return (char_str);
}		/* -----  end of function ft_memset  ----- */
