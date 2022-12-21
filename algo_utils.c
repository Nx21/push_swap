/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:02:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/12/21 20:19:38 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dt_swap_a(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_a < 2)
		return (-1);
	swap_a(stack, 0);
	fb = decision_tree(stack, number, bp);
	swap_a(stack, 0);
	return (fb + 1);
}

int	dt_swap_b(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_b < 2)
		return (-1);
	swap_b(stack, 0);
	fb = decision_tree(stack, number, bp);
	swap_b(stack, 0);
	return (fb + 1);
}

int	dt_swap_s(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_a < 2 || stack->len_b < 2)
		return (-1);
	swap_ab(stack, 0);
	fb = decision_tree(stack, number, bp);
	swap_ab(stack, 0);
	return (fb + 1);
}

int	dt_push_a(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (!stack->stack_b)
		return (-1);
	push_a(stack, 0);
	fb = decision_tree(stack, number, bp);
	push_b(stack, 0);
	return (fb + 1);
}

int	dt_push_b(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (!stack->stack_a)
		return (-1);
	push_b(stack, 0);
	fb = decision_tree(stack, number, bp);
	push_a(stack, 0);
	return (fb + 1);
}
