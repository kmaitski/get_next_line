/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:36:13 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/26 17:11:20 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_atoi
 *  Description:  Converts the string argument str to an integer (type int).
 * =============================================================================
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = 1;
	while (*str > 0 && *str < 33 && *str != '\e')
		str++;
	if (*str == '-')
		is_negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result < 0)
			break ;
	}
	if (result == -2147483648)
		return (-2147483648);
	if (result < 0 && is_negative == -1)
		return (0);
	if (result < 0 && is_negative == 1)
		return (-1);
	return (result * is_negative);
}		/* -----  end of function ft_atoi  ----- */
