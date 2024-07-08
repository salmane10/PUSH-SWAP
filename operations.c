/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:50:49 by slouham           #+#    #+#             */
/*   Updated: 2024/07/03 18:53:39 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_node **stack, char s_name)
{
	int		t;
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	t = first->num;
	first->num = second->num;
	second->num = t;
	if (s_name == 'a')
		write(1, "sa\n", 3);
	if (s_name == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, '\0');
	swap(stack_b, '\0');
	write(1, "ss\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	if (*stack_b)
	{
		node = *stack_b;
		*stack_b = (*stack_b)->next;
		node->next = *stack_a;
		*stack_a = node;
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_node	*node;

	if (*stack_a)
	{
		node = *stack_a;
		*stack_a = (*stack_a)->next;
		node->next = *stack_b;
		*stack_b = node;
		write(1, "pb\n", 3);
	}
}
