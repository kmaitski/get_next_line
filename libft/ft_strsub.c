/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:27:54 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:09:01 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strsub
 *  Description:  Allocates and returns a “fresh” substring from the string
 *  			  given as argument. The substring begins at indexstart and is
 *  			  of size len. If start and len aren’t refering to a valid
 *  			  substring, the behavior is undefined. If the allocation fails,
 *  			  the function returns NULL.
 * =====================================================================================
 */
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}		/* -----  end of function ft_strsub  ----- */
