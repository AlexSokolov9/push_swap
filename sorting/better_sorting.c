/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:01:14 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 07:23:42 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *one, int *two)
{
	int	temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

int	find_median(int argc, char *argv[])
{
	int	i;
	int	j;
	int	size;
	int	*copy;

	size = argc - 1;
	i = -1;
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (0);
	while (++i < argc - 1)
		copy[i] = ft_atoi(argv[i + 1]);
	i = -1;
	while (++i < size - 1)
	{
		j = i - 1;
		while (++j < size)
			if (copy[i] > copy[j])
				swap(&copy[i], &copy[j]);
	}
	i = -1;
	while (++i != argc / 2)
		j = copy[i];
	free(copy);
	return (j);
}

void	init_min_mid_max_struct(t_min_max *v, t_s_main vl)
{
	int	i;

	v->max = ft_atoi(vl.argv[1]);
	v->min = ft_atoi(vl.argv[1]);
	i = 1;
	while (i < vl.argcc)
	{
		if (ft_atoi(vl.argv[i]) > v->max)
			v->max = ft_atoi(vl.argv[i]);
		i++;
	}
	i = 1;
	while (i < vl.argcc)
	{
		if (ft_atoi(vl.argv[i]) < v->min)
			v->min = ft_atoi(vl.argv[i]);
		i++;
	}
	v->mid = find_median(vl.argcc, vl.argv);
}

void	find_already_sorted(struct s_Node **a, t_min_max v)
{
	struct s_Node	*tmp;

	tmp = *a;
	if (tmp->nbr == v.max)
		return ;
	while (tmp->nbr != v.min || tmp->next != NULL)
	{
		if (tmp->next->nbr == v.max)
		{
			tmp->score = 1;
			ra(*a);
			return ;
		}
		if (tmp->nbr == v.min || tmp->next != NULL)
		{
			tmp->next->score = 1;
			return ;
		}
		if (tmp->next->nbr == v.max)
			break ;
		tmp = tmp->next;
	}
}
