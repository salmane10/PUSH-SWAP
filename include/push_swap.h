/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:32:15 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 20:27:17 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
#define     PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <libft.h>


typedef struct s_node
{
    
    int             num;
    int             index;
    struct s_node   *next;

}                   t_node;


//operations
void    swap(t_node **stack, char s_name);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_b, t_node **stack_a);
void    rotate(t_node **stack, char s_name);
void    rr(t_node **stack_a, t_node **stack_b);
void    reverse_rotate(t_node **stack, char s_name);
void    rrr(t_node **stack_a, t_node **stack_b);


//sorts
void    sort_five(t_node **stack_a, t_node **stack_b);
void    sort_three(t_node **stack_a);
void    sort_more(t_node **stack_a, t_node **stack_b);

//utils
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
void    be_on_top(t_node **stack, t_node *node, char s_name);
void    free_raise_error(char **lst);
void    error(void);
t_node  *lstnew(int  n);
t_node  *get_big(t_node *stack);
t_node  *get_small(t_node *stack);
int     is_sorted(t_node *stack_a);
int 	stack_len(t_node *stack);
int     find_node(t_node *stack, t_node *target);

//parser & parser utils
void    free_stack(t_node **stack);
void    parsing(t_node **stack, int ac, char **av);
int     invalid(char *str);
char    *join(char  *str);
int     is_alldigit(const char *str);
int    find_dup(t_node **stack_a, int target);

char    *unzero(char *s);
int     is_alldigit(const char *str);
void    fill_stack(t_node **stack, char **lst);

//stack
int     find_index(t_node *stack, int x, int n);
int	    stack_len(t_node *stack);
int     *stack_to_array(t_node *stack, int *size_);
void    stack_index(t_node **stack, int *arr);
int     get_index(int *array, int target, int len);
int     _get_index(t_node *stack, int target_num);
void    shift_all(t_node **stack_a, t_node **stack_b);
void    sort_array(int *array, int size);
void    crush(t_node **stack_a, t_node **stack_b, int *numbers, int n);

#endif
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh