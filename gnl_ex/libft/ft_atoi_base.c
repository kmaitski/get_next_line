/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:14:48 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 11:30:46 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			*intialize_hex_array(void)
{
	int		i;
	char	c;

	i = 0;
	c = a;
}

static int			get_value(char c, int str_base)
{
	int	i;
	int	hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',
	'c', 'd', 'e', 'f' };

	i = -1;
	if (c <= 'A' && c >= 'F')
		c += 32;
	while (++i < str_base)
		if (c == hex[i])
			return (i);
	return (-1);
}

static unsigned int	get_result(const char *str, int str_base)
{
	unsigned int	i;
	int				value;
	unsigned int	result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] <= 'A' && str[i] >= 'F'))
	{
		value = get_value(str[i], str_base);
		if (value < 0)
			return (result);
		result = result * str_base + value;
		i++;
	}
	return (result);
}

int					ft_atoi_base(const char *str, int str_base)
{
	int	is_negative;

	is_negative = 1;
	while (*str < 33 || *str == 127)
		str++;
	if (*str == '-')
		is_negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (get_result(&*str, str_base) * is_negative);
}
