/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:55:54 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 08:55:51 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	not_nbr(t_s_main vl)
{
	int	i;
	int	j;

	i = 1;
	while (i != vl.argcc)
	{
		j = 0;
		while (vl.argv[i][j] != '\0')
		{
			if ((vl.argv[i][0] == '-' || vl.argv[i][0] == '+')
				&& vl.argv[i][1] == '\0')
			{
				return (1);
			}
			else if ((vl.argv[i][j] != '-' && vl.argv[i][j] != '+')
					&& (vl.argv[i][j] < '0' || vl.argv[i][j] > '9'))
			{
				return (2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	bigger_than_integer(t_s_main vl)
{
	int	i;

	i = 1;
	while (i != vl.argcc)
	{
		if (ft_atoi(vl.argv[i]) < -2147483648
			|| ft_atoi(vl.argv[i]) > 2147483647)
			return (3);
		i++;
	}
	return (0);
}

int	*malloc_temp_int(int *tmp, t_s_main vl)
{
	int	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * vl.argcc);
	if (!tmp)
		return (NULL);
	while (i < vl.argcc)
	{
		tmp[i] = ft_atoi(vl.argv[i]);
		i++;
	}
	return (tmp);
}

int	duplicated(t_s_main vl)
{
	int	*tmp;
	int	i;
	int	j;
	int	t;

	tmp = NULL;
	tmp = malloc_temp_int(tmp, vl);
	i = 0;
	while (++i < vl.argcc)
	{
		j = 0;
		t = tmp[i];
		while (++j < vl.argcc)
		{
			if ((t == tmp[j] && j != i)
				|| (ft_atoi(vl.argv[0]) == tmp[j] && vl.ac2 == 1))
			{
				free(tmp);
				return (4);
			}
		}
	}
	free(tmp);
	return (0);
}

int	error_checker(t_s_main vl)
{
	if (not_nbr(vl) > 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (bigger_than_integer(vl) > 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (duplicated(vl) > 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
