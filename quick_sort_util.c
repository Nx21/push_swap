/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:46:41 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:08:56 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stacks *stack, int num, int avg)
{
	while (stack->len_b <= num + avg)
	{
		if (!stack->stack_a)
			return ;
		if (stack->stack_a->val >= num && stack->stack_a->val <= num + avg)
			push_b(stack, 1);
		else if (stack->stack_b && (stack->stack_b->val >= num) \
		&& (stack->stack_b->val < num + avg / 2))
			rotate_ab(stack, 1);
		else
			rotate_a(stack, 1);
	}
}

int	find(int num, t_stacks *stack)
{
	t_stack	*b;
	int		i;

	i = 0;
	b = stack->stack_b;
	while (i < stack->len_b)
	{
		if (b->val == num)
			return (i);
		b = b->next;
		i++;
	}
	return (i);
}

int	sort_rest(t_stacks *stack)
{
	if (stack->stack_a->val > stack->stack_a->prev->val)
		rotate_a(stack, 1);
	else if (stack->stack_a->val > stack->stack_a->next->val)
		swap_a(stack, 1);
	else
		return (0);
	return (1);
}
