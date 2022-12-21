/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:17 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 15:37:13 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stacks	*stack;

	stack = stacks_make(argv, argc);
	if (!stack)
		return (0);
	if (stack->size > 5 && feed_back(stack))
		quick_sort(stack);
	while (decision_tree(stack, 7, 7))
		;
	free_all(stack);
}
