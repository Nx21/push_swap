/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:38:09 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:34:20 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

t_stack	*make_stack(const char **list, int len)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = NULL;
	while (i < len)
	{
		str_to_int(list[i], &head);
		i++;
	}
	return (head);
}

void	make_stack_from_list(t_stack *stack_a, int *arr)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stack_a;
	while (node->next)
	{
		node->val = arr[i];
		i++;
		node = node->next;
	}
	node->val = arr[i];
	stack_a->prev = node;
	node->next = stack_a;
}

void	sort_arr(int i, t_stack *number1, int *arr, t_stacks *stacks)
{
	t_stack		*number2;
	int			j;

	number2 = stacks->stack_a;
	j = 0;
	arr[i] = 0;
	while (j < i)
	{
		if (number1->val > number2->val)
			arr[i]++;
		else if (number1->val < number2->val)
			arr[j]++;
		else
		{
			free(arr);
			error_head(stacks->stack_a);
		}
		j++;
		number2 = number2->next;
	}
}

t_stacks	*remake_strucks(t_stacks *stacks)
{
	t_stack	*number1;
	int		i;
	int		*arr;

	arr = (int *) malloc(stacks->size * sizeof(int));
	arr[0] = 0;
	i = 1;
	number1 = stacks->stack_a->next;
	while (i < stacks->size)
	{
		sort_arr(i, number1, arr, stacks);
		i++;
		number1 = number1->next;
	}
	make_stack_from_list(stacks->stack_a, arr);
	free(arr);
	return (stacks);
}

t_stacks	*stacks_make(const char **list, int len)
{
	t_stacks	*stacks;
	t_stack		*head;
	int			i;

	i = 0;
	head = make_stack(list, len);
	if (head == NULL)
		return (NULL);
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = head;
	while (head)
	{
		i++;
		head = head->next;
	}
	stacks->size = i;
	stacks->len_a = i;
	stacks->stack_b = NULL;
	stacks->len_b = 0;
	return (remake_strucks(stacks));
}
