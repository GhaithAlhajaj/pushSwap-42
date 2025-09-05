/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:50:32 by galhajaj          #+#    #+#             */
/*   Updated: 2025/04/16 00:59:51 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node *alloc_node(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	(void)a;
	(void)b;
	if (!node)
		return (NULL);
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	free_split(char **split)
{
	int i = 0;

	if (!split)
		return;
	while (split[i])
		free(split[i++]);
	free(split);
}
void    free_stack(t_node *head)
{
    t_node *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
