/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:43:06 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 15:19:15 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

void	free_stack(t_stack *head)
{
	t_stack	*next;

	if (!head)
		return ;
	if (head->prev)
		head->prev->next = NULL;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void	error_head(t_stack *head)
{
	free_stack(head);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_stacks *stack)
{
	free_stack(stack->stack_a);
	free_stack(stack->stack_b);
	free(stack);
}

void	error_checker(t_stacks *stack, char *step)
{
	if (*step)
		free(step);
	free_all(stack);
	write(2, "Error\n", 6);
	exit(1);
}
