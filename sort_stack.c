/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:26:32 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/07 11:34:17 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, int len)
{
	t_node	*stack_b;

	stack_b = NULL;
	if ((is_sorted(stack_a)) == 0)
	{
		if (len == 2)
			swap_a(stack_a);
		else if (len == 3)
			sort_three(stack_a);
		else
		{
			if (len == 4)
				sort_four(stack_a, &stack_b);
			else if (len == 5)
				sort_five(stack_a, &stack_b);
			else
				sort_algo(stack_a, &stack_b);
		}
	}
	ft_free(&stack_b);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	sec;
	int	third;

	first = (*stack_a)->value;
	sec = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > sec && sec < third && third > first)
		swap_a(stack_a);
	else if ((first > third && sec < first) && sec > third)
	{
		swap_a(stack_a);
		rra(stack_a);
	}
	else if ((first > third && sec < first) && sec < third)
		rotate_a(stack_a);
	else if (first < sec && first < third && sec > third)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (first < sec && first > third && sec > third)
		rra(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int		min;
	t_node	*tmp;

	tmp = *stack_a;
	min = tmp->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	while ((*stack_a)->value != min)
	{
		if (get_position(*stack_a, min) <= 2)
			rotate_a(stack_a);
		else
			rra(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int		min;
	t_node	*tmp;

	tmp = *stack_a;
	min = tmp->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	while ((*stack_a)->value != min)
	{
		if (get_position(*stack_a, min) <= 2)
			rotate_a(stack_a);
		else
			rra(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

int	get_position(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}
