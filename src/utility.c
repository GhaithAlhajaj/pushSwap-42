/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:01:33 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 01:01:13 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	quick_sort(int arr[], int l, int r)
{
	int	s;
	int	e;
	int	pivot;
	int	tmp;

	s = l;
	e = r;
	pivot = arr[(l + r) / 2];
	if (l >= r)
		return ;
	while (s <= e)
	{
		while (arr[s] < pivot)
			s++;
		while (arr[e] > pivot)
			e--;
		if (s <= e)
		{
			tmp = arr[s];
			arr[s++] = arr[e];
			arr[e--] = tmp;
		}
	}
	quick_sort(arr, l, e);
	quick_sort(arr, s, r);
}

int	get_mid(t_stack *stack, int size)
{
	int		i;
	int		arr[5];
	t_node	*cur;

	i = -1;
	cur = stack->top;
	while (++i < size && cur)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, size - 1);
	return (arr[2]);
}

long	get_max(t_stack *stack, int size)
{
	t_node	*cur;
	long	max;

	cur = stack->top;
	max = MININT;
	while (size-- && cur)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

long	get_min(t_stack *stack, int size)
{
	t_node	*cur;
	long	min;

	cur = stack->top;
	min = MAXINT;
	while (size-- && cur)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
	}
	return (min);
}

void	init_var(t_stack *stack, t_var *var, int size)
{
	long	max;
	long	min;

	var->size_l = 0;
	var->size_m = 0;
	var->size_s = 0;
	max = get_max(stack, size);
	min = get_min(stack, size);
	var->pivot_s = (max + 2 * min) / 3;
	var->pivot_l = (2 * max + min) / 3;
}
