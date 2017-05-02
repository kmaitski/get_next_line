/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:20:35 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 17:48:23 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  int_len
 *  Description:  Calculates the number of digits in the int.
 * =============================================================================
 */
static	int	int_len(int n)
{
	unsigned int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}		/* -----  end of function int_len  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_itoa
 *  Description:  Allocate and returns a “fresh” string representing the integer
 *  			  n given as argument. Negative numbers must be supported. If
 *  			  the allocation fails, the function returns NULL.
 * =============================================================================
 */
char		*ft_itoa(int n)
{
	unsigned int	i;
	char			*fresh;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = int_len(n);
	if (!(fresh = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		fresh[0] = '-';
		n *= -1;
	}
	fresh[--i] = n % 10 + '0';
	while (n /= 10)
		fresh[--i] = n % 10 + '0';
	return (fresh);
}		/* -----  end of function ft_itoa  ----- */
