/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:25:26 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 20:45:06 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


t_node  *s_append(t_node **stack, int n)
{
    t_node *new;
    t_node *last;
    
    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->num = n;
    new->next = NULL;
    if (*stack == NULL)
        *stack = new;
    else
    {
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = new;
    }
    return new;
}

long int	ps_atoi(const char *n)
{
	long int	i;
	long int	r;
	long int	s;

	i = 0;
	r = 0;
	s = 1;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-')
	{
		i++;
		s = -1;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] <= '9' && n[i] >= '0')
		r = ((r * 10) + n[i++]) - '0';
	return (r * s);
}

int     valid_int(char *p)
{
    char    *tmp;    
    long     n;

    n = ps_atoi(p);
    tmp = unzero(p);
    if (ft_strlen(tmp) >= 11 || n < INT_MIN || n > INT_MAX)
        return (free(tmp), 1);
    return (free(tmp), 0);
}

void    fill_stack(t_node **stack, char **lst)
{
    int i;
    int r;

    r = 0;
    i = 0;
    while (lst[i])
    {
        r = valid_int(lst[i]);
        if (r)
        {
            free_stack(stack);
            free_raise_error(lst);
        }
        s_append(stack, ft_atoi(lst[i++]));
    }
}