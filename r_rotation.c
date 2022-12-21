/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:34 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:14:37 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	r_rotate_a(t_stacks *stack, int cas)
{
	if (stack->stack_a)
	{
		stack->stack_a = stack->stack_a->prev;
		if (cas)
			write(1, "rra\n", 4);
	}
}

void	r_rotate_b(t_stacks *stack, int cas)
{
	if (stack->stack_b)
	{
		stack->stack_b = stack->stack_b->prev;
		if (cas)
			write(1, "rrb\n", 4);
	}
}

void	r_rotate_ab(t_stacks *stack, int cas)
{
	if (stack->stack_b && stack->stack_b)
	{
		r_rotate_a(stack, 0);
		r_rotate_b(stack, 0);
		if (cas)
			write(1, "rrr\n", 4);
	}
}
