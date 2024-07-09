/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:24:23 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 22:01:45 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_node *stack, int *size_)
{
	int	i;
	int	size;
	int	*array;

	i = 0;
	size = stack_len(stack);
	array = (int *)malloc(sizeof(int) * size);
	ft_bzero((void *)array, (sizeof(int) * size));
	while (stack)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	if (size_)
		*size_ = size;
	return (array);
}

int	find_index(t_node *stack, int x, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index <= x || stack->index <= (x + n))
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_index(int *array, int target, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (target == array[i])
			return (i);
		i++;
	}
	return (0);
}

void	stack_index(t_node **stack, int *arr)
{
	t_node	*stack_;

	stack_ = *stack;
	while (stack_)
	{
		stack_->index = get_index(arr, stack_->num, stack_len(*stack));
		stack_ = stack_->next;
	}
}

int	_get_index(t_node *stack, int target_num)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->num == target_num)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
