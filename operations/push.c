/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:34:08 by asokolov          #+#    #+#             */
/*   Updated: 2022/04/29 23:49:39 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	p_base(struct s_Node **first, struct s_Node **second)
{
	struct s_Node	*tmp;

	tmp = (*first)->next;
	if ((*first) == NULL)
		return ;
	(*first)->next = (*second);
	(*second) = (*first);
	(*first) = tmp;
}

void	pa(struct s_Node **a, struct s_Node **b)
{
	p_base(b, a);
	write(1, "pa\n", 3);
}

void	pb(struct s_Node **a, struct s_Node **b)
{
	p_base(a, b);
	write(1, "pb\n", 3);
}
