/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:37:21 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:49:38 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	remove_a(t_stacks *stack, t_stack *node)
{
	if (stack->stack_a->next == node)
		stack->stack_a = NULL;
	else
	{
		stack->stack_a->prev->next = stack->stack_a->next;
		stack->stack_a->next->prev = stack->stack_a->prev;
		stack->stack_a = stack->stack_a->next;
	}
}

void	add_b(t_stacks *stack, t_stack *node)
{
	if (stack->stack_b == NULL)
	{
		stack->stack_b = node;
		stack->stack_b->next = node;
		stack->stack_b->prev = node;
	}
	else
	{
		node->next = stack->stack_b;
		node->prev = stack->stack_b->prev;
		stack->stack_b->prev->next = node;
		stack->stack_b->prev = node;
		stack->stack_b = node;
	}
}

void	push_b(t_stacks *stack, int st)
{
	t_stack	*node;

	if (!stack->stack_a)
		return ;
	if (st)
		write(1, "pb\n", 3);
	node = stack->stack_a;
	remove_a(stack, node);
	add_b(stack, node);
	stack->len_b++;
	stack->len_a--;
}
