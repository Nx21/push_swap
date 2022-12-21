/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_make_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:38:09 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 15:16:49 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonc.h"

int	add_number(long number, t_stack **head, int neg)
{
	t_stack	*new_stack;
	t_stack	*stack;

	if (!number && neg < 0)
		error_head(*head);
	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack || number > 2147483648 || (neg == 1 && number == 2147483648))
		error_head(*head);
	new_stack->val = (int)number * neg;
	new_stack->next = NULL;
	if (*head == NULL)
		*head = new_stack;
	else
	{
		stack = *head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = new_stack;
		new_stack->prev = stack;
	}
	return (0);
}

void	ft_atois(const char *str, t_stack **head, int *j)
{
	long	num;
	int		neg;

	neg = 1;
	num = 0;
	if (str[*j] == '-')
		neg = -1;
	if (str[*j] == '+' || str[*j] == '-')
		(*j)++;
	while (str[*j] && str[*j] != ' ')
	{
		if (str[*j] >= '0' && str[*j] <= '9')
		{
			num *= 10;
			num += str[*j] - '0';
			if (num > 2147483648 || (neg == 1 && num == 2147483648))
				error_head(*head);
		}
		else
			error_head(*head);
		(*j)++;
	}
	if (add_number(num, head, neg))
		error_head(*head);
}

void	str_to_int(const char *str, t_stack **head)
{
	int	j;

	j = 0;
	while (str[j] == ' ')
		j++;
	if (!str[j])
		error_head(*head);
	while (str[j])
	{
		ft_atois(str, head, &j);
		while (str[j] == ' ')
			j++;
	}
}
