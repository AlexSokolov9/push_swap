/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_scores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:20:07 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/03 03:04:59 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	score_a_following(t_score val, struct s_Node *tmp_a)
{
	if (val.i <= val.j)
	{
		val.u = val.i;
		while (val.u != 0)
		{
			tmp_a = tmp_a->next;
			val.u--;
		}
		tmp_a->score = val.i;
		return (val.i);
	}
	else
	{
		val.u = val.i;
		while (val.u != 0)
		{
			tmp_a = tmp_a->next;
			val.u--;
		}
		tmp_a->score = val.j;
		return (val.j);
	}
	return (0);
}

int	score_a(struct s_Node **a, struct s_Node **b, int max)
{
	struct s_Node	*a1;
	struct s_Node	*tmp_a;
	t_score			val;

	a1 = *a;
	tmp_a = *a;
	init_helpers_struct(&val);
	if ((*a) == NULL || (*b) == NULL)
		return (0);
	val.bigger_than_b = almost_smallest_nbr(tmp_a, (*b)->nbr, max);
	val.size = list_size(tmp_a);
	if (tmp_a->nbr > (*b)->nbr && tmp_a->nbr == val.bigger_than_b)
		tmp_a->score = 0;
	else
	{
		all_scores_to_zero(&tmp_a);
		while (a1->nbr != val.bigger_than_b)
		{
			val.i++;
			a1 = a1->next;
		}
		val.j = val.size - val.i;
		return (score_a_following(val, tmp_a));
	}
	return (0);
}

void	small_score_of_b(struct s_Node **b)
{
	struct s_Node	*tmp_b;
	t_score			val;

	tmp_b = *b;
	init_helpers_struct(&val);
	val.size = list_size(tmp_b) / 2;
	if ((*b) == NULL)
		return ;
	if (val.size != 0)
		val.one_or_zero = list_size(tmp_b) % 2;
	while (++val.ii != val.size)
	{
		tmp_b->score = val.ii;
		tmp_b = tmp_b->next;
	}
	if (val.one_or_zero == 1 && val.size != 1)
		val.ii++;
	while (tmp_b != NULL)
	{
		if (val.one_or_zero == 1 && val.size == 1 && tmp_b->next == NULL)
			val.ii++;
		tmp_b->score = val.ii;
		tmp_b = tmp_b->next;
		val.ii--;
	}
}

void	final_score_of_b(struct s_Node **a, struct s_Node **b, int max)
{
	struct s_Node	*tmp_b;
	int				i;

	tmp_b = *b;
	i = 0;
	if ((*b) == NULL || (*a) == NULL)
		return ;
	small_score_of_b(&tmp_b);
	while (tmp_b != NULL)
	{
		i = score_a(a, &tmp_b, max);
		tmp_b->score += i;
		tmp_b = tmp_b->next;
	}
}
