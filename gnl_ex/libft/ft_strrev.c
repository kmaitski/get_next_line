/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:48:20 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:23:36 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strrev
 *  Description:  Reverses (in-place) a string.
 * =============================================================================
 */
char	*ft_strrev(char *str)
{
	int				i;
	int				j;
	char			k;

	i = ft_strlen(str);
	j = -1;
	while (++j < --i)
	{
		k = str[j];
		str[j] = str[i];
		str[i] = k;
	}
	return (str);
}		/* -----  end of function ft_strrev  ----- */
