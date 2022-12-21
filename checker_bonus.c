/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:42:21 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 15:25:16 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_compare(char *a, char *b)
{
	int	i;

	i = 0;
	while (b[i] || a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

void	do_step(t_stacks *stack, char *step)
{
	if (ft_compare(step, "sa"))
		swap_a(stack, 0);
	else if (ft_compare(step, "sb"))
		swap_b(stack, 0);
	else if (ft_compare(step, "ss"))
		swap_ab(stack, 0);
	else if (ft_compare(step, "ra"))
		rotate_a(stack, 0);
	else if (ft_compare(step, "rb"))
		rotate_b(stack, 0);
	else if (ft_compare(step, "rr"))
		rotate_ab(stack, 0);
	else if (ft_compare(step, "rra"))
		r_rotate_a(stack, 0);
	else if (ft_compare(step, "rrb"))
		r_rotate_b(stack, 0);
	else if (ft_compare(step, "rrr"))
		r_rotate_ab(stack, 0);
	else if (ft_compare(step, "pa"))
		push_a(stack, 0);
	else if (ft_compare(step, "pb"))
		push_b(stack, 0);
	else
		error_checker(stack, step);
}

int	ft_read(char *step, t_stacks *stack)
{
	char	c;
	int		i;

	i = 0;
	if (!read(0, &c, 1))
		return (0);
	while (c != '\n')
	{
		if (i < 4)
			step[i] = c;
		i++;
		read(0, &c, 1);
	}
	if (i > 3)
		error_checker(stack, step);
	step[i] = 0;
	do_step(stack, step);
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_stacks	*stack;
	char		*step;
	int			c;

	stack = stacks_make(argv, argc);
	if (!stack)
		return (0);
	c = 1;
	step = (char *)malloc(sizeof(char) * 5);
	c = ft_read(step, stack);
	while (c)
		c = ft_read(step, stack);
	if (feed_back(stack))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(step);
	free_all(stack);
	return (0);
}
