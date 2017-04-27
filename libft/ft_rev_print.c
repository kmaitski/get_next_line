/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:45:53 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 20:51:32 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_rev_print
 *  Description:  Takes a string, and displays the string in reverse on the
 *  			  standard output.
 * =============================================================================
 */
void	ft_rev_print(char *str)
{
	unsigned int	i;

	i = ft_strlen(str);
	while (i--)
		write(1, &str[i], 1);
}		/* -----  end of function ft_rev_print  ----- */
