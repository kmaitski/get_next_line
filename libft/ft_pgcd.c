/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 08:09:48 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:15:08 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_pgcd
 *  Description:  Takes ints and returns their highest common denominator.
 * =============================================================================
 */
int	ft_pgcd(unsigned int nbr1, unsigned int nbr2)
{
	unsigned int	denominator;
	unsigned int	highest_denominator;

	denominator = 1;
	highest_denominator = 0;
	while (denominator <= nbr1 && denominator <= nbr2)
	{
		if (!(nbr1 % denominator) && !(nbr2 % denominator))
			highest_denominator = denominator;
		denominator++;
	}
	return (highest_denominator);
}		/* -----  end of function ft_pgcd  ----- */
