/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:47:40 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:20:01 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_do_op
 *  Description:  Return the result of the requested arithmetic operation. You
 *  			  can assume the string have no mistakes or extraneous
 *  			  characters. Negative numbers, in input or output, will have
 *  			  one and only one leading '-'. The result of the operation fits
 *  			  in an int.
 * =============================================================================
 */
int	ft_do_op(int number1, char sign, int number2)
{
	if (sign == '+')
		return (number1 + number2);
	if (sign == '-')
		return (number1 - number2);
	if (sign == '*')
		return (number1 * number2);
	if (sign == '/')
		return (number1 / number2);
	if (sign == '%')
		return (number1 % number2);
	else
		return (0);
}		/* -----  end of function ft_do_op  ----- */
