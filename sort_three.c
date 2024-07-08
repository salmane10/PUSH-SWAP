/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:45:39 by slouham           #+#    #+#             */
/*   Updated: 2024/06/23 11:28:14 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*lkbir;

	lkbir = get_big(*stack_a);
	if (lkbir == *stack_a)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next == lkbir)
		reverse_rotate(stack_a, 'a');
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap(stack_a, 'a');
}
