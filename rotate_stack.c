/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:17:55 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/07 11:17:13 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*current;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = first_node;
	first_node->prev = current;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}
