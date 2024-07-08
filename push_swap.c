/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:20:05 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 20:44:34 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (ac == 1)
        return (0);
    else
    {   
        parsing(&stack_a, ac, av);
        // while (stack_a)
        // {
        //     printf("%i\n", stack_a->num);
        //     stack_a = stack_a->next;
        // }
        // exit(0);
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
                //printf("sort more hh \n");
        }
        free_stack(&stack_a);
    }
}


// acb -> rra -> bac -> sa -> abc
// bac -> sa -> abc
// bca -> rra -> abc
// cab -> ra -> abc
// cba -> sa -> rra


// "42 11 12 13 "
// ./push_swap 42 "11 12 13" -1 -9 "14" -8 "15 16"
// -> "0 11 12 13 -1 -9 14 -8 15 16 "
// lst: str = [ 0, 11, 12, 13, -1, -9, 14, -8, 15, 16 ]
// 
