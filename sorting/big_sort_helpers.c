/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:20:01 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/03 03:13:25 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_helpers_struct(t_score *val)
{
	val->i = 0;
	val->j = 0;
	val->u = 0;
	val->size = 0;
	val->bigger_than_b = 0;
	val->one_or_zero = 0;
	val->ii = -1;
}

void	all_scores_to_zero(struct s_Node **a)
{
	struct s_Node	*tmp;

	tmp = *a;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp->score = 0;
		tmp = tmp->next;
	}
}

int	smallest_score(struct s_Node *head)
{
	int	min;

	min = 2147483647;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (min > head->score)
			min = head->score;
		head = head->next;
	}
	return (min);
}

//      smallest nbr between first b->nbr and max in A
//      we need it to find the right place for b->nbr in A

int	almost_smallest_nbr(struct s_Node *head, int nbr_b, int max)
{
	int	min;

	min = max;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (min > head->nbr && head->nbr > nbr_b)
			min = head->nbr;
		head = head->next;
	}
	return (min);
}
