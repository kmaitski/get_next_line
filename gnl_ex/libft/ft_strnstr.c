/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:18:53 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:11:39 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  is_needle_in_haystack
 *  Description:  After the first character in the needle string is found in the
 *  			  haystack string this function determines if it is indeed the
 *  			  needle that you have found.
 * =============================================================================
 */
static int	is_needle_in_haystack(const char *haystack, const char *needle,
		size_t needle_length, size_t len)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0' && haystack[i] == needle[i])
		i++;
	if (i == needle_length && i <= len)
		return (1);
	return (0);
}		/* -----  end of function is_needle_in_haystack  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strnstr
 *  Description:  Locates the first occurrence of the null-terminated string
 *  			  neddle in the string haystack, where not more than len
 *  			  characters are searched. Characters that appear after a `\0'
 *  			  character are not searched.
 * =============================================================================
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			needle_length;

	i = 0;
	needle_length = ft_strlen(needle);
	if (!needle[0] || haystack == needle)
		return ((char *)haystack);
	while (haystack[i++] && i + needle_length <= len)
		if (haystack[i] == needle[0])
			if (is_needle_in_haystack(&haystack[i], needle,
						needle_length, len) == 1)
				return ((char *)&haystack[i]);
	return (NULL);
}		/* -----  end of function ft_strnstr  ----- */
