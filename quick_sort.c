/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:46:41 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:12:03 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort_b(t_stacks *stack, int k)
{
	int	i;
	int	min;

	i = stack->size / k;
	min = 0;
	while (stack->len_a > 3)
	{
		sort_b(stack, min, i);
		min += i;
		if (k > 3)
			k--;
		i = stack->len_a / k;
		if (i < 10)
			i = stack->len_a - 3;
	}
}

int	push_from_up(t_stacks *stack, int number)
{
	while (stack->stack_b && stack->stack_b->val != stack->stack_a->val - 1)
	{
		if (stack->stack_b && stack->stack_b->val > number)
		{
			number = stack->stack_b->val;
			push_a(stack, 1);
			if (stack->stack_b->val < number)
				rotate_ab(stack, 1);
			else
				rotate_a(stack, 1);
		}
		else
			rotate_b(stack, 1);
	}
	return (number);
}

int	push_from_down(t_stacks *stack, int number)
{
	while (stack->stack_b && stack->stack_b->val != stack->stack_a->val - 1)
	{
		if (stack->stack_b && stack->stack_b->val > number \
		&& stack->stack_b->val < stack->stack_b->prev->val)
		{
			number = stack->stack_b->val;
			push_a(stack, 1);
			rotate_a(stack, 1);
		}
		else
			r_rotate_b(stack, 1);
	}
	return (number);
}

void	quick_sort(t_stacks *stack)
{
	int	number;
	int	max_val;

	push_sort_b(stack, stack->size / 100 + 2);
	while (sort_rest(stack))
		;
	while (stack->len_b)
	{
		number = 0;
		if (stack->stack_a->val > stack->stack_a->prev->val)
			number = stack->stack_a->prev->val;
		max_val = find(stack->stack_a->val - 1, stack);
		if (max_val < stack->len_b / 2)
			number = push_from_up(stack, number);
		else
			number = push_from_down(stack, number);
		push_a(stack, 1);
		while (stack->stack_a->prev->val == stack->stack_a->val - 1)
		{
			r_rotate_a(stack, 1);
			number--;
		}
	}
}
