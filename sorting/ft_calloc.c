/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:01:14 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/06 11:25:38 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)b;
	i = 0;
	while (i < (int)len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (char *)malloc(count * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, '\0', (count * size));
	return ((void *)(dest));
}
