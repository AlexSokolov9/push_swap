/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:05:41 by asokolov          #+#    #+#             */
/*   Updated: 2022/05/07 08:25:54 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

struct	s_Node
{
	int				nbr;
	int				score;
	struct s_Node	*next;
};

typedef struct s_min_max
{
	int		min;
	int		mid;
	int		max;
}	t_min_max;

typedef struct s_score
{
	int		i;
	int		j;
	int		u;
	int		size;
	int		bigger_than_b;
	int		one_or_zero;
	int		ii;
}	t_score;

typedef struct s_main
{
	int		i;
	int		ac2;
	int		argcc;
	char	**argv;
}	t_s_main;

void	sa(struct s_Node *head);
void	sb(struct s_Node *head);
void	ss(struct s_Node *head_a, struct s_Node *head_b);
void	pa(struct s_Node **a, struct s_Node **b);
void	pb(struct s_Node **a, struct s_Node **b);
void	ra(struct s_Node *head);
void	rb(struct s_Node *head);
void	rr(struct s_Node *head_a, struct s_Node *head_b);
void	rra(struct s_Node **head);
void	rrb(struct s_Node **head);
void	rrr(struct s_Node **head_a, struct s_Node **head_b);

void	init_helpers_struct(t_score *val);
void	all_scores_to_zero(struct s_Node **a);
int		smallest_score(struct s_Node *head);
int		almost_smallest_nbr(struct s_Node *head, int nbr_b, int max);

void	rotate_a(struct s_Node **a, struct s_Node **b, int max);
void	rotate_b(struct s_Node **a, struct s_Node **b, int max);

int		score_a(struct s_Node **a, struct s_Node **b, int max);
void	small_score_of_b(struct s_Node **b);
void	final_score_of_b(struct s_Node **a, struct s_Node **b, int max);

void	big_sorting(struct s_Node **a, struct s_Node **b, t_min_max v);

long	ft_atoi(const char *str);

char	**ft_split(char const *s, char c);
char	**ft_free_mallocs(char **res, int j);

void	*ft_calloc(size_t count, size_t size);

void	malloc_node_to_the_end(struct s_Node **a, int nbr, int score);
void	free_list(struct s_Node **a);
int		ft_count_tabs(char const *s, char c);

void	small_sorting_a(struct s_Node **a);
void	small_sorting_b(struct s_Node **b);
void	join_small_sorting(struct s_Node **a, struct s_Node **b, int min);

int		sorted(struct s_Node *head);
int		biggest_nbr(struct s_Node *head);
int		smallest_nbr(struct s_Node *head);
int		list_size(struct s_Node *head);
void	do_final_ra_or_rra(struct s_Node **a, int min);

int		error_checker(t_s_main vl);

int		find_median(int argc, char *argv[]);
void	init_min_mid_max_struct(t_min_max *v, t_s_main vl);
void	find_already_sorted(struct s_Node **a, t_min_max v);

#endif
