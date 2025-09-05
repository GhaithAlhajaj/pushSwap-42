/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:11:22 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:19:02 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	long			data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

typedef struct s_var
{
	int				size_l;
	int				size_m;
	int				size_s;
	long			pivot_l;
	long			pivot_s;
}					t_var;

void	            free_nodes(t_stack *stack);
int		safe_atoi(char *arg, t_stack *a, t_stack *b, char **s);
void	push_argv(int argc, char *argv[], t_stack *a, t_stack *b);
void	ft_exit1(const char *str, t_stack *a, t_stack *b, char **s);
void    free_stack(t_node *head);
int					valid_dup(t_stack *stack);
int					valid_a_sort(t_stack *a, int size);
int					valid_b_sort(t_stack *b, int size);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

int					get_mid(t_stack *stack, int size);
long				get_max(t_stack *stack, int size);
long				get_min(t_stack *stack, int size);
void				init_var(t_stack *stack, t_var *var, int size);
void				a_to_b(t_stack *a, t_stack *b, int size, int *first);
void				b_to_a(t_stack *a, t_stack *b, int size, int *first);
void				sort_small_a(t_stack *a, t_stack *b, int size);
void				sort_a_two(t_stack *a);
void				sort_a_three(t_stack *a);
void				divide_a_four(t_stack *a, t_stack *b, int size);
void				divide_a_five(t_stack *a, t_stack *b, int size);
void				sort_small_b(t_stack *a, t_stack *b, int size);
void				sort_b_two(t_stack *a, t_stack *b);
void				divide_b_four(t_stack *a, t_stack *b, int size);
void				divide_b_five(t_stack *a, t_stack *b, int size);

t_node *alloc_node(t_stack *a, t_stack *b);
void				free_split(char **split);

#endif
