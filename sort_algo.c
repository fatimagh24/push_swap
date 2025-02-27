/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:06:58 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/07 11:58:10 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_node **stack_a)
{
	int		counter;
	t_node	*tmp;
	t_node	*st_a;

	tmp = *stack_a;
	while (tmp)
	{
		counter = 0;
		st_a = *stack_a;
		while (st_a)
		{
			if (st_a->value < tmp->value)
				counter++;
			st_a = st_a->next;
		}
		tmp->index = counter;
		tmp = tmp->next;
	}
}

int	get_max(t_node **stack_a)
{
	int		max;
	int		max_b;
	t_node	*temp;

	if (!stack_a || !(*stack_a))
		return (0);
	temp = *stack_a;
	max = temp->value;
	temp = temp->next;
	max_b = 0;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

void	fix_index(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->value = tmp->index;
		tmp = tmp->next;
	}
}

void	radix_sort(int max, t_node **stack_a, t_node **stack_b, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->value >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (stack_len(stack_b) > 0)
			push_a(stack_a, stack_b);
		if (is_sorted(stack_a))
			break ;
		i++;
	}
}

void	sort_algo(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	size;

	give_index(stack_a);
	fix_index(stack_a);
	size = stack_len(stack_a);
	max = get_max(stack_a);
	radix_sort(max, stack_a, stack_b, size);
}
