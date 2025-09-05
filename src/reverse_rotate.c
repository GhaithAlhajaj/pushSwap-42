/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:01:17 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:00:19 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*bottom_prev;

	if (stack->size <= 1)
		return ;
	bottom_prev = stack->bottom->prev;
	bottom_prev->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = bottom_prev;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
