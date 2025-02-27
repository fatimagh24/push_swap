/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:11:47 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/29 16:18:40 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_r(t_node **stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	while (first->next != NULL)
		first = first->next;
	last = first;
	if (first->prev)
		first->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	reverse_r(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **stack_b)
{
	reverse_r(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **stack_b, t_node **stack_a)
{
	reverse_r(stack_b);
	reverse_r(stack_a);
	ft_putstr_fd("rrr\n", 1);
}
