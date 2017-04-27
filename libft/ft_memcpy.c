/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:52:56 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 18:39:29 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ft_memcpy
 *  Description:  Copies n characters from memory area str2 to memory area str1.
 * =====================================================================================
 */
void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*char_str1;
	const char	*char_str2;
	size_t		i;

	char_str1 = str1;
	char_str2 = str2;
	i = -1;
	while (++i < n)
		char_str1[i] = char_str2[i];
	return (char_str1);
}		/* -----  end of function ft_memcpy  ----- */
