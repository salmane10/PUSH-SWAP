/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:43 by slouham           #+#    #+#             */
/*   Updated: 2024/07/08 21:41:23 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concate(int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	i = 1;
	while (i < ac)
	{
		if (invalid((char *)av[i]))
		{
			free(str);
			error();
		}
		tmp = str;
		str = join(ft_strjoin(str, av[i++]));
		free(tmp);
	}
	return (str);
}

int	check_lst(char **lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst[i])
	{
		j = 0;
		if ((lst[i][j] == '-' || lst[i][j] == '+') && lst[i][j + 1] != '\0')
			j++;
		if (is_alldigit(&lst[i][j]))
			return (1);
		i++;
	}
	return (0);
}

void	check_dup(t_node **stack)
{
	t_node	*stack_;

	stack_ = *stack;
	while (stack_)
	{
		if (find_dup(stack, stack_->num) > 1)
		{
			free_stack(stack);
			error();
		}
		stack_ = stack_->next;
	}
}

void	parsing(t_node **stack, int ac, char **av)
{
	char	*str;
	char	**lst;
	int		i;

	str = concate(ac, av);
	lst = ft_split(str, ' ');
	free(str);
	if (check_lst(lst))
		free_raise_error(lst);
	else
		fill_stack(stack, lst);
	check_dup(stack);
	i = 0;
	while (lst[i])
		free(lst[i++]);
	free(lst);
}
