/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:11:15 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:01:20 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	valid_dup(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;

	cur = stack->top;
	while (cur->next)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	valid_a_sort(t_stack *a, int size)
{
	t_node	*cur;

	cur = a->top;
	size--;
	while (cur->next && size--)
	{
		if (cur->data >= cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	valid_b_sort(t_stack *b, int size)
{
	t_node	*cur;

	cur = b->top;
	size--;
	while (cur->next && size--)
	{
		if (cur->data <= cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}
