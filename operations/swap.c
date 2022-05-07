/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:42:06 by asokolov          #+#    #+#             */
/*   Updated: 2022/04/29 23:50:09 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	s_base(struct s_Node *head)
{
	int	tmp;

	tmp = 0;
	tmp = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = tmp;
}

void	sa(struct s_Node *head)
{
	s_base(head);
	write(1, "sa\n", 3);
}

void	sb(struct s_Node *head)
{
	s_base(head);
	write(1, "sb\n", 3);
}

void	ss(struct s_Node *head_a, struct s_Node *head_b)
{
	s_base(head_a);
	s_base(head_b);
	write(1, "ss\n", 3);
}
