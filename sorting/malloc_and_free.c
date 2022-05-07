/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:33:52 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/06 10:59:49 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	malloc_node_to_the_end(struct s_Node **head, int nbr, int score)
{
	struct s_Node	*new_node;
	struct s_Node	*last_node;

	new_node = (struct s_Node *)malloc(sizeof (struct s_Node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	new_node->score = score;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

void	free_list(struct s_Node **a)
{
	struct s_Node	*current_node;
	struct s_Node	*next_node;

	current_node = *a;
	if (*a == NULL)
		return ;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*a = NULL;
}
