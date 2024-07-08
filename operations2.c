/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:37:20 by slouham           #+#    #+#             */
/*   Updated: 2024/06/23 09:29:45 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_node **stack, char s_name)
{
    t_node *top;

    if (stack == 0 || (*stack)->next == 0)
        return ;
    top = *stack;
    *stack = (*stack)->next;
    top->next = NULL;
    ft_lstadd_back(stack, top);
    if (s_name == 'a')
        write(1, "ra\n", 3);
    if (s_name == 'b')
        write(1, "rb\n", 3);
}

void    rr(t_node **stack_a, t_node **stack_b)
{
    if (!stack_a || !stack_b)
        return ;
    
    rotate(stack_a, '\0');
    rotate(stack_b, '\0');
    write(1, "rr\n", 3);
    
}

void    reverse_rotate(t_node **stack, char s_name)
{
    t_node *tmp;

    if (stack == 0 || (*stack)->next == 0)
        return ;
    tmp = *stack;
    while (tmp->next->next != 0)
        tmp = tmp->next;
    ft_lstadd_front(stack, tmp->next);
    tmp->next = NULL;
    if (s_name  == 'a')
        write(1, "rra\n", 4);
    if (s_name == 'b')
        write(1, "rrb\n", 4);
}

void    rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a, '\0');
    reverse_rotate(stack_b, '\0');
    write(1, "rrr\n", 4);
}