/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   intiate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:45:19 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/25 11:56:36 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int argc, char **argv, t_node **stack_a)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		add_stack(stack_a, ft_atoi(argv[i]));
		i++;
	}
	len = stack_len(stack_a);
	sort_stack(stack_a, len);
}

void	add_stack(t_node **stack, int data)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
}

void	optimize(int arc, char **arv, t_node **stack_a)
{
	int		i;
	long	res;

	i = 1;
	res = 0;
	while (i < arc)
	{
		res = ft_atol(arv[i]);
		if (res > INT_MAX || res < INT_MIN)
			error(2, stack_a);
		if (res == 0 && ft_strcmp(arv[i], "0") != 0)
			return ;
		i++;
	}
	parsing(arc, arv, stack_a);
}
