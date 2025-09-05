/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 04:02:12 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:05:05 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exit1(const char *str, t_stack *a, t_stack *b, char **s)
{
	free_stack(a->top);
	free_stack(b->top);
	free_split(s);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	free_nodes(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		first;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	push_argv(argc, argv, &a, &b);
	if (valid_dup(&a))
		ft_exit1("Error\n", &a, &b, NULL);
	if (valid_a_sort(&a, a.size))
	{
		free_stack(a.top);
		free_stack(b.top);
		return (0);
	}
	first = 1;
	a_to_b(&a, &b, a.size, &first);
	free_stack(a.top);
	free_stack(b.top);
	return (0);
}
