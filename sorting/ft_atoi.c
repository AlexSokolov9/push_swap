/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:00:36 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/06 09:31:31 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	r;

	r = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13) || *str == 22)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - 48;
		str++;
		if (r * sign > 2147483647)
			return (2147483648);
		else if (r * sign < -2147483648)
			return (-2147483649);
	}
	return (sign * (int)r);
}
