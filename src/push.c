/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:11:02 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 00:59:37 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_src_one(t_stack *src, t_stack *dst)
{
	if (dst->size == 0)
	{
		dst->top = src->top;
		dst->bottom = src->top;
	}
	else
	{
		dst->top->prev = src->top;
		dst->top->prev->next = dst->top;
		dst->top = dst->top->prev;
	}
	src->top = NULL;
	src->bottom = NULL;
	src->size--;
	dst->size++;
}

static void	push(t_stack *src, t_stack *dst)
{
	if (src->size == 0)
		return ;
	else if (src->size == 1)
		push_src_one(src, dst);
	else if (src->size > 1)
	{
		if (dst->size == 0)
		{
			dst->top = src->top;
			dst->bottom = src->top;
			src->top = src->top->next;
			dst->top->next = NULL;
		}
		else if (dst->size > 0)
		{
			dst->top->prev = src->top;
			src->top = src->top->next;
			dst->top->prev->next = dst->top;
			dst->top = dst->top->prev;
		}
		src->top->prev = NULL;
	}
	src->size--;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr("pb\n");
}
