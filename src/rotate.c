/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:22:26 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/15 01:00:28 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2 || !stack->top || !stack->bottom)
		return ;
	first = stack->top;
	second = first->next;
	stack->top = second;
	stack->top->prev = NULL;
	stack->bottom->next = first;
	first->prev = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
