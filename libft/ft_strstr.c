/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:38:17 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:11:09 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  is_needle_in_haystack
 *  Description:  After matching a character in haystack with the first
 *  			  character of needle check to see if the needle is found in
 *  			  haystack.
 * =============================================================================
 */
static int	is_needle_in_haystack(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	while (needle[i] && haystack[i] == needle[i])
		i++;
	if (i == needle_len)
		return (1);
	return (0);
}		/* -----  end of function is_needle_in_haystack  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strstr
 *  Description:  Finds the first occurrence of the substring needle in the
 *  			  string haystack. The terminating '\0' characters are not
 *  			  compared.
 * =============================================================================
 */
char		*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	while (*haystack++)
		if (*haystack == *needle)
			if (is_needle_in_haystack(haystack, needle) == 1)
				return ((char*)haystack);
	return (NULL);
}		/* -----  end of function ft_strstr  ----- */
