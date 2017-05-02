/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:47:57 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:22:01 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_print_bits
 *  Description:  Takes a byte and prints it in binary.
 * =============================================================================
 */
void	ft_print_bits(unsigned char octet)
{
	unsigned int	i;

	i = 8;
	while (i--)
	{
		if (octet / 128)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet <<= 1;
	}
}		/* -----  end of function ft_print_bits  ----- */
