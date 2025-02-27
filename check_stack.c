/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:16:48 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/07 11:30:24 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char **arv, int arc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < arc)
	{
		j = i + 1;
		while (j > i && j < arc)
		{
			if (ft_strcmp(arv[i], arv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_num(char *arv)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (arv[i] == '-' || arv[i] == '+')
		i++;
	if (!arv[i])
		return (0);
	while (arv[i])
	{
		if (!(ft_isdigit(arv[i])))
			sign = 0;
		i++;
	}
	return (sign);
}

int	is_sorted(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_node **stack)
{
	int		len;
	t_node	*temp;

	if (!stack || !(*stack))
		return (0);
	len = 0;
	temp = *stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
