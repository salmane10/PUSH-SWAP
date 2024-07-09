/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:20:05 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 22:05:18 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	else
	{
		parsing(&stack_a, ac, av);
		if (!is_sorted(stack_a))
		{
			if (stack_len(stack_a) == 2)
				swap(&stack_a, 'a');
			else if (stack_len(stack_a) == 3)
				sort_three(&stack_a);
			else if (stack_len(stack_a) == 5)
				sort_five(&stack_a, &stack_b);
			else
				sort_more(&stack_a, &stack_b);
		}
		free_stack(&stack_a);
	}
}
