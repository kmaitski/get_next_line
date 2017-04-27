/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:46:09 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 19:30:37 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strrchr
 *  Description:  Searches for the last occurrence of the character c (an
 *  			  unsigned char) in the string pointed to, by the argument str.
 * =============================================================================
 */
char	*ft_strrchr(const char *str, int c)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	while (str_len && str[str_len] != c)
		str_len--;
	if (str[str_len] == c)
		return ((char *)&str[str_len]);
	return (NULL);
}		/* -----  end of function ft_strrchr  ----- */
