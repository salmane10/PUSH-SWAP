/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:42:05 by slouham           #+#    #+#             */
/*   Updated: 2024/06/23 19:55:32 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*sghir;

	while (stack_len(*stack_a) > 3)
	{
		sghir = get_small(*stack_a);
		be_on_top(stack_a, sghir, 'a');
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (stack_len(*stack_b))
		pa(stack_a, stack_b);
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap(stack_a, 'a');
}
