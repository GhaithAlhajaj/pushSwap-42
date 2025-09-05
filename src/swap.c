/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:04:50 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:01:02 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size <= 1)
		return ;
	first = stack->top;
	second = stack->top->next;
	if (stack->size >= 3)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
