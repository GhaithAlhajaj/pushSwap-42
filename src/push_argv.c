/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:50:32 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 00:59:51 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	valid_arg_len(char *arg, t_stack *a, t_stack *b, char **s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] == '0')
		i++;
	while (arg[i++])
		len++;
	if (len > 10)
		ft_exit1("Error\n", a, b, s);
}

int	safe_atoi(char *arg, t_stack *a, t_stack *b, char **s)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	valid_arg_len(arg, a, b, s);
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	if (!arg[i])
		ft_exit1("Error\n", a, b, s);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_exit1("Error\n", a, b, s);
		num = num * 10 + (arg[i++] - '0');
	}
	num *= sign;
	return ((int)num);
}

static void	push_node(t_stack *stack, t_node *new)
{
	if (!stack->size)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

void	push_argv(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char	**split;
	t_node	*node;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
			ft_exit1("Error\n", a, b, split);
		j = -1;
		while (split[++j])
		{
			node = alloc_node(a, b);
			if (!node)
				ft_exit1("Error\n", a, b, split);
			push_node(a, node);
			node->data = safe_atoi(split[j], a, b, split);
		}
		free_split(split);
	}
}