/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:30:35 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 21:37:42 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*node;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		node = *lst;
		while (node->next != 0)
			node = node->next;
		node->next = new;
	}
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_node	*get_big(t_node *stack)
{
	t_node	*big;

	if (!stack)
		return (NULL);
	big = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->num > big->num)
			big = stack;
		stack = stack->next;
	}
	return (big);
}

t_node	*get_small(t_node *stack)
{
	t_node	*small;

	if (!stack)
		return (NULL);
	small = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->num < small->num)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
