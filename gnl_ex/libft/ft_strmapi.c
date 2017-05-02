/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:23:56 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:08:47 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strmapi
 *  Description:  Applies the function f to each character of the string passed
 *  			  as argument by giving its index as first argument to create a
 *  			  “fresh” new string resulting from the successive applications 
 *  			  of f.
 * =============================================================================
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s || !f)
		return (0);
	new = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (new == NULL)
		return (0);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}	  /* -----  end of function ft_strmapi  ----- */
