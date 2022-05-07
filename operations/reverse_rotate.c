/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:40:59 by asokolov          #+#    #+#             */
/*   Updated: 2022/04/29 23:50:05 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrr_base(struct s_Node **head)
{
	struct s_Node	*tmp;
	struct s_Node	*last;

	tmp = NULL;
	last = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(struct s_Node **head)
{
	rrr_base(head);
	write(1, "rra\n", 4);
}

void	rrb(struct s_Node **head)
{
	rrr_base(head);
	write(1, "rrb\n", 4);
}

void	rrr(struct s_Node **head_a, struct s_Node **head_b)
{
	rrr_base(head_a);
	rrr_base(head_b);
	write(1, "rrr\n", 4);
}
