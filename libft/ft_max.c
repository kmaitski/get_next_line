/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:47:06 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:11:36 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_max
 *  Description:  Returns the largest number found in the array pointed to by
 *  			  tab.
 * =============================================================================
 */
int	ft_max(int *tab, unsigned int len)
{
	int		max;

	max = -2147483648;
	if (!len || !tab)
		return (0);
	while (len--)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	return (max);
}		/* -----  end of function ft_max  ----- */
