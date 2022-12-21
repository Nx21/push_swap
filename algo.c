/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:02:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 12:46:36 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dt_ra(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_a < 3)
		return (-1);
	rotate_a(stack, 0);
	fb = decision_tree(stack, number, bp);
	r_rotate_a(stack, 0);
	return (fb + 1);
}

int	dt_rb(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_b < 3)
		return (-1);
	rotate_b(stack, 0);
	fb = decision_tree(stack, number, bp);
	r_rotate_b(stack, 0);
	return (fb + 1);
}

int	dt_rra(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_a < 3)
		return (-1);
	r_rotate_a(stack, 0);
	fb = decision_tree(stack, number, bp);
	rotate_a(stack, 0);
	return (fb + 1);
}

int	dt_rrb(t_stacks *stack, int number, int bp)
{
	int	fb;

	if (stack->len_b < 3)
		return (-1);
	r_rotate_b(stack, 0);
	fb = decision_tree(stack, number, bp);
	rotate_b(stack, 0);
	return (fb + 1);
}
