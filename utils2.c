/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:47:23 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 21:34:26 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew(int n)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = n;
	new->next = NULL;
	return (new);
}

int	find_node(t_node *stack, t_node *target)
{
	int		pos;
	t_node	*curr;

	pos = 0;
	curr = stack;
	while (curr)
	{
		if (curr == target)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

void	be_on_top(t_node **stack, t_node *node, char s_name)
{
	int	op;
	int	len;
	int	pos;

	(void)s_name;
	op = -1;
	len = stack_len(*stack);
	pos = find_node(*stack, node);
	if (pos == -1)
		return ;
	if (pos > len / 2)
		op = 1;
	else
		op = 0;
	while (*stack != node)
	{
		if (op == 0)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
}
