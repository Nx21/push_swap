/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:37:21 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 14:31:11 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	remove_b(t_stacks *stack, t_stack *node)
{
	if (stack->stack_b->next == node)
		stack->stack_b = NULL;
	else
	{
		stack->stack_b->prev->next = stack->stack_b->next;
		stack->stack_b->next->prev = stack->stack_b->prev;
		stack->stack_b = stack->stack_b->next;
	}
}

void	add_a(t_stacks *stack, t_stack *node)
{
	if (stack->stack_a == NULL)
	{
		stack->stack_a = node;
		stack->stack_a->next = node;
		stack->stack_a->prev = node;
	}
	else
	{
		node->next = stack->stack_a;
		node->prev = stack->stack_a->prev;
		stack->stack_a->prev->next = node;
		stack->stack_a->prev = node;
		stack->stack_a = node;
	}
}

void	push_a(t_stacks *stack, int st)
{
	t_stack	*node;

	if (!stack->stack_b)
		return ;
	if (st)
		write(1, "pa\n", 3);
	node = stack->stack_b;
	remove_b(stack, node);
	add_a(stack, node);
	stack->len_a++;
	stack->len_b--;
}
