/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:18:11 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:35:50 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	swap_a(t_stacks *stack, int cas)
{
	int	swap;

	if (stack->len_a < 2)
		return ;
	if (cas)
		write(1, "sa\n", 3);
	swap = stack->stack_a->val;
	stack->stack_a->val = stack->stack_a->next->val;
	stack->stack_a->next->val = swap;
}

void	swap_b(t_stacks *stack, int cas)
{
	int	swap;

	if (stack->len_b < 2)
		return ;
	if (cas)
		write(1, "sb\n", 3);
	swap = stack->stack_b->val;
	stack->stack_b->val = stack->stack_b->next->val;
	stack->stack_b->next->val = swap;
}

void	swap_ab(t_stacks *stack, int cas)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	if (cas)
		write(1, "ss\n", 3);
}
