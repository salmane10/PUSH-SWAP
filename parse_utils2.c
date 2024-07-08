/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:55:37 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 21:35:58 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_alldigit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *str)
{
	char	*p;

	p = ft_strjoin(str, " ");
	free(str);
	return (p);
}

int	invalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j == i);
}

int	find_dup(t_node **stack_a, int target)
{
	t_node	*stack;
	int		c;

	c = 0;
	stack = *stack_a;
	while (stack)
	{
		if (stack->num == target)
			c++;
		stack = stack->next;
	}
	return (c);
}

char	*unzero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	return (ft_substr(s, i, ft_strlen(s)));
}
