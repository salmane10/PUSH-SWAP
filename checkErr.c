/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkErr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:34 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 20:42:56 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void free_raise_error(char **lst)
{
    int i;

    i = 0;
    if (lst)
    {
        while (lst[i])
            free(lst[i++]);
        free(lst);
    }
    write(2, "Error\n", 6);
    exit(1);
}

int is_sorted(t_node *stack_a)
{
    while (stack_a && stack_a->next)
    {
        if (stack_a->num > stack_a->next->num)
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
}

void    free_stack(t_node **stack)
{
    t_node	*current;
	t_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
    *stack = NULL;
}
