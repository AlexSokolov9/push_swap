/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:04:01 by asokolov          #+#    #+#             */
/*   Updated: 2022/04/29 23:50:21 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(struct s_Node *head)
{
	if (head == NULL || head->next == NULL)
		return (1);
	return ((head->nbr < head->next->nbr) && sorted(head->next));
}

int	biggest_nbr(struct s_Node *head)
{
	int	max;

	max = -2147483648;
	while (head != NULL)
	{
		if (max < head->nbr)
		max = head->nbr;
		head = head->next;
	}
	return (max);
}

int	smallest_nbr(struct s_Node *head)
{
	int	min;

	min = 2147483647;
	while (head != NULL)
	{
		if (min > head->nbr)
			min = head->nbr;
		head = head->next;
	}
	return (min);
}

int	list_size(struct s_Node *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	do_final_ra_or_rra(struct s_Node **a, int min)
{
	struct s_Node	*tmp_a;
	int				size;
	int				i;
	int				j;

	tmp_a = *a;
	size = list_size(*a);
	i = 0;
	j = 0;
	while (tmp_a->nbr != min)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	j = size / 2;
	if (i <= j)
		while (sorted(*a) != 1)
			ra(*a);
	else
		while (sorted(*a) != 1)
			rra(a);
}
