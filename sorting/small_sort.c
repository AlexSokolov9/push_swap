/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:02:50 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 08:16:48 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_sorting_a(struct s_Node **a)
{
	while (sorted(*a) != 1)
	{
		if (biggest_nbr(*a) == (*a)->next->next->nbr)
			sa(*a);
		else if (biggest_nbr(*a) == (*a)->nbr)
			ra(*a);
		else if (sorted(*a) != 1)
			rra(a);
	}
}

void	small_sorting_b(struct s_Node **b)
{
	while (sorted(*b) != 1)
	{
		if (biggest_nbr(*b) == (*b)->next->next->nbr)
			sb(*b);
		else if (biggest_nbr(*b) == (*b)->nbr)
			rb(*b);
		else if (sorted(*b) != 1)
			rrb(b);
	}
}

void	join_small_sorting(struct s_Node **a, struct s_Node **b, int min)
{
	while (*b != NULL)
	{
		if ((*b)->nbr < (*a)->nbr)
			pa(a, b);
		else if ((*b)->nbr > biggest_nbr(*a) && (*a)->nbr == smallest_nbr(*a))
			pa(a, b);
		ra(*a);
	}
	do_final_ra_or_rra(a, min);
}
