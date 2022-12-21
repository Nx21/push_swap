/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:41:34 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:14:43 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	rotate_a(t_stacks *stack, int cas)
{
	if (stack->stack_a)
	{
		stack->stack_a = stack->stack_a->next;
		if (cas)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stacks *stack, int cas)
{
	if (stack->stack_b)
	{
		stack->stack_b = stack->stack_b->next;
		if (cas)
			write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_stacks *stack, int cas)
{
	if (stack->stack_b && stack->stack_b)
	{
		rotate_a(stack, 0);
		rotate_b(stack, 0);
		if (cas)
			write(1, "rr\n", 3);
	}
}
