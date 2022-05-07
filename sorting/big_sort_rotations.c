/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:20:05 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/03 03:15:59 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(struct s_Node **a, struct s_Node **b, int max)
{
	struct s_Node	*tmp_a;
	int				sc;
	int				size;
	int				i;

	tmp_a = *a;
	sc = score_a(a, b, max) + 1;
	size = list_size(*a);
	i = 0;
	if ((*b) == NULL || (*a) == NULL || (*b)->score == 0)
		return ;
	while (tmp_a != NULL && tmp_a->score != (sc - 1))
	{
		i++;
		tmp_a = tmp_a->next;
	}
	if (i > size / 2)
		while (--sc != 0)
			rra(a);
	else
		while (--sc != 0)
			ra(*a);
}

void	rotate_b_following(struct s_Node *tmp_b, struct s_Node **b, t_score	val)
{
	val.j = val.i;
	while (val.j != 0)
	{
		(tmp_b->score)--;
		rb(*b);
		val.j--;
	}
}

void	rotate_b(struct s_Node **a, struct s_Node **b, int max)
{
	struct s_Node	*tmp_b;
	int				size;
	int				sc;
	t_score			val;

	tmp_b = *b;
	size = list_size(tmp_b);
	sc = smallest_score(tmp_b);
	init_helpers_struct(&val);
	if ((*b) == NULL || (*a) == NULL || (*b)->score == 0)
		return ;
	else
	{
		while (tmp_b->score != sc && ++val.i)
			tmp_b = tmp_b->next;
		val.j = size - val.i;
		if ((val.i <= val.j))
			rotate_b_following(tmp_b, b, val);
		else
			while (tmp_b->score != score_a(a, b, max) && (tmp_b->score)--)
				rrb(b);
	}
}
