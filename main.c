/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:05:13 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 08:56:11 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_s_main(t_s_main *vl, int argc)
{
	vl->i = 0;
	vl->ac2 = 0;
	vl->argcc = argc;
	vl->argv = NULL;
}

void	m_free(struct s_Node **a, t_s_main vl)
{
	if (vl.ac2 == 1)
		ft_free_mallocs(vl.argv, vl.argcc);
	free_list(a);
}

void	m(t_s_main vl, struct s_Node **a, struct s_Node **b, t_min_max v)
{
	if (vl.argcc > 4 && vl.argcc <= 7)
	{
		if (vl.argcc == 7)
		{
			pb(a, b);
			pb(a, b);
			pb(a, b);
			small_sorting_b(b);
		}
		if (vl.argcc == 6)
		{
			pb(a, b);
			pb(a, b);
			if (sorted(*b) != 1)
				sb(*b);
		}
		if (vl.argcc == 5)
			pb(a, b);
		small_sorting_a(a);
		join_small_sorting(a, b, v.min);
	}
	else
		big_sorting(a, b, v);
}

int	m_all(t_min_max v, t_s_main vl, struct s_Node **a, struct s_Node **b)
{
	if (vl.argcc == 1 || error_checker(vl) > 0)
	{
		m_free(a, vl);
		return (0);
	}
	init_min_mid_max_struct(&v, vl);
	while (++vl.i < vl.argcc)
		malloc_node_to_the_end(a, ft_atoi(vl.argv[vl.i]), 0);
	if (vl.ac2 == 1)
		vl.argcc++;
	if (sorted(*a) == 1)
		;
	else if (vl.argcc == 3)
		sa(*a);
	else if (vl.argcc == 4)
		small_sorting_a(a);
	else
	{
		find_already_sorted(a, v);
		m(vl, a, b, v);
	}
	if (vl.ac2 == 1)
		vl.argcc--;
	m_free(a, vl);
	return (0);
}

int	main(int argc, char *ar[])
{
	t_min_max		v;
	t_s_main		vl;
	struct s_Node	*a;
	struct s_Node	*b;

	a = NULL;
	b = NULL;
	init_s_main(&vl, argc);
	if (vl.argcc == 2 && ft_count_tabs(ar[1], ' ') > 1)
	{
		vl.i = -1;
		vl.ac2 = 1;
		vl.argcc = 0;
		vl.argv = ft_split(ar[1], ' ');
		while (vl.argv[vl.argcc] != NULL)
			vl.argcc++;
	}
	else
		vl.argv = ar;
	return (m_all(v, vl, &a, &b));
	return (0);
}
