/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:04:51 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/06 07:28:06 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	b_s_following(struct s_Node **a, struct s_Node **b, t_min_max v)
{
	final_score_of_b(a, b, v.max);
	rotate_b(a, b, v.max);
	rotate_a(a, b, v.max);
	while ((*b) != NULL)
	{
		pa(a, b);
		final_score_of_b(a, b, v.max);
		rotate_b(a, b, v.max);
		rotate_a(a, b, v.max);
	}
	do_final_ra_or_rra(a, v.min);
	all_scores_to_zero(a);
}

void	big_sorting(struct s_Node **a, struct s_Node **b, t_min_max v)
{
	if ((*a) == NULL)
		return ;
	while (sorted(*a) != 1)
	{
		if ((*a)->nbr == v.min || (*a)->nbr == v.max || (*a)->score == 1)
		{
			(*a)->score = 0;
			ra((*a));
		}
		else
		{
			if ((*a)->nbr < v.mid)
				pb(a, b);
			else
			{
				pb(a, b);
				rb(*b);
			}
		}
	}
	all_scores_to_zero(a);
	all_scores_to_zero(b);
	b_s_following(a, b, v);
}
