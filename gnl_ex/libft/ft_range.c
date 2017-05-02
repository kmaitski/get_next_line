/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:41:12 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 15:53:15 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  get_range
 *  Description:  Returns the range for ft_range to allocate enough memory using 
 *  			  malloc.
 * =============================================================================
 */

static unsigned int	get_range (int start, int end)
{
	unsigned int	range;

	range = 0;
	if (start > end)
		range = start - end + 1;
	else
		range = end - start + 1;
	return ((unsigned)range);
}		/* -----  end of function get_range  ----- */

/* 
 * ===  FUNCTION  ===============================================================
 *         Name:  ft_range
 *  Description:  It must allocate (with malloc()) an array of integers, fill it
 *  			  with consecutive values that begin at start and end at end 
 *  			  (Including start and end !), then return a pointer to the first
 *  			  value of the array.
 * ==============================================================================
 */
int					*ft_range (int start, int end)
{
	unsigned int	range;
	int				*array;
	unsigned int	i;
	
	i = 0;
	range = get_range(start, end);
	if(!(array = (int *)malloc(sizeof(int) * range)))
		return (NULL);
	if (range == 1)
		array[0] = start;
	else if (start > end)
		while (i < range)
			array[i++] = start--;
	else if (end > start)
		while (i < range)
			array[i++] = start++;
	return (array);
}		/* -----  end of function ft_range  ----- */
