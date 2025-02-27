/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:44:18 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/29 16:29:30 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int fd, t_node **stack)
{
	if (fd == 2)
		ft_putstr_fd("Error\n", 2);
	else
		ft_putstr_fd("Error\n", 1);
	if (*stack && stack)
		ft_free(stack);
	exit (1);
}

void	ft_free(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_exit(t_node **stack_a)
{
	ft_free(stack_a);
	exit(1);
}
