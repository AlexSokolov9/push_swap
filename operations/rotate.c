/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:41:16 by asokolov          #+#    #+#             */
/*   Updated: 2022/04/29 23:50:07 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_base(struct s_Node *head)
{
	struct s_Node	*tmp;
	int				first_nbr;
	int				first_score;

	tmp = head;
	first_nbr = tmp->nbr;
	first_score = tmp->score;
	while (tmp->next != NULL)
	{
		tmp->nbr = tmp->next->nbr;
		tmp->score = tmp->next->score;
		tmp = tmp->next;
	}
	tmp->nbr = first_nbr;
	tmp->score = first_score;
}

void	ra(struct s_Node *head)
{
	r_base(head);
	write(1, "ra\n", 3);
}

void	rb(struct s_Node *head)
{
	r_base(head);
	write(1, "rb\n", 3);
}

void	rr(struct s_Node *head_a, struct s_Node *head_b)
{
	r_base(head_a);
	r_base(head_b);
	write(1, "rr\n", 3);
}
