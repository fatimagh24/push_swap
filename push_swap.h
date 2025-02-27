/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:14:05 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/07 11:59:49 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		is_num(char *arv);
int		check_dup(char **arv, int arc);
int		is_sorted(t_node **stack);
int		stack_len(t_node **stack_a);
int		get_position(t_node *stack, int value);
int		get_max(t_node **stack_a);
void	ft_free(t_node **stack);
void	error(int fd, t_node **stack);
void	optimize(int arc, char **arv, t_node **stack_a);
void	add_stack(t_node **stack_a, int data);
void	parsing(int argc, char **argv, t_node **stack_a);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rrr(t_node **stack_b, t_node **stack_a);
void	rrb(t_node **stack_b);
void	rra(t_node **stack_a);
void	reverse_r(t_node **stack);
void	sort_stack(t_node **stack_a, int len);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	ft_exit(t_node **stack_a);
void	sort_algo(t_node **stack_a, t_node **stack_b);
void	radix_sort(int max, t_node **stack_a, t_node **stack_b, int size);
void	fix_index(t_node **stack_a);
void	give_index(t_node **stack_a);
#endif