/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:46:00 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 12:59:25 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

int	feed_back(t_stacks *stack)
{
	t_stack	*node;
	int		result;
	int		i;

	result = 0;
	node = stack->stack_a;
	i = 0;
	while (i < stack->len_a - 1 && stack->stack_a)
	{
		result += node->next->val < node->val;
		i++;
		node = node->next;
	}
	node = stack->stack_b;
	i = 0;
	while (i < stack->len_b - 1 && stack->stack_b)
	{
		result += node->next->val > node->val;
		i++;
		node = node->next;
	}
	return (2 * result + stack->len_b);
}
