/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:24:05 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 21:36:42 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_array(int *array, int size)
{
	int	x;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				x = array[i];
				array[i] = array[j];
				array[j] = x;
			}
			j++;
		}
		i++;
	}
}

void	crush(t_node **stack_a, t_node **stack_b, int *numbers, int n)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(*stack_a);
	stack_index(stack_a, numbers);
	while (i < len)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_b, stack_a);
			rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= (i + n))
		{
			pb(stack_b, stack_a);
			i++;
		}
		else if (find_index(*stack_a, i, n) < (stack_len(*stack_a) / 2))
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}

void	shift_all(t_node **stack_a, t_node **stack_b)
{
	int	biggest;
	int	len;
	int	i;

	biggest = get_big(*stack_b)->num;
	len = stack_len(*stack_b);
	i = _get_index(*stack_b, biggest);
	while (len)
	{
		if ((*stack_b)->num == biggest)
		{
			pa(stack_a, stack_b);
			len--;
			if (*stack_b == NULL)
				biggest = 0;
			else
				biggest = get_big(*stack_b)->num;
			i = _get_index(*stack_b, biggest);
		}
		else if (i < len / 2)
			rotate(stack_b, 'b');
		else
			reverse_rotate(stack_b, 'b');
	}
}

void	sort_more(t_node **stack_a, t_node **stack_b)
{
	int	chunk_size;
	int	*array;

	chunk_size = 15;
	if (stack_len(*stack_a) > 400)
		chunk_size *= 2;
	array = stack_to_array(*stack_a, (void *)0);
	sort_array(array, stack_len(*stack_a));
	crush(stack_a, stack_b, array, chunk_size);
	shift_all(stack_a, stack_b);
	free(array);
}
