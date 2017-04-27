/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:46:07 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:58:56 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_search_and_replace
 *  Description:  While in str change characters that match the first
 *  			  character, i, with the second character, j.
 * =============================================================================
 */
char	*ft_search_and_replace(char *str, char i, char j)
{
	int	k;

	k = -1;
	while (str[++k])
		if (str[k] == i)
			str[k] = j;
	return (str);
}		/* -----  end of function ft_search_and_replace  ----- */
