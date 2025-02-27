/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:59:26 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/29 16:30:29 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a)
{
	int	data;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	data = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = data;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_node **stack_b)
{
	int	data;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	data = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = data;
	ft_putstr_fd("sb\n", 1);
}
