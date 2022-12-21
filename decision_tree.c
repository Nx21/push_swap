/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:08:10 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 12:56:27 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int *fb)
{
	int	i;
	int	idx;

	idx = 0;
	while (idx < 9 && fb[idx] == -1)
	idx++;
	i = idx + 1;
	while (i < 8)
	{
		if (fb[i] < fb[idx] && fb[i] >= 0)
			idx = i;
		i++;
	}
	return (idx);
}

int	*min_algo(t_stacks *stack, int number, int bp)
{
	int	*fd;

	fd = (int *)malloc(sizeof(int) * 9);
	fd[0] = dt_push_b(stack, number, bp);
	fd[1] = dt_ra(stack, number, bp);
	fd[2] = dt_rb(stack, number, bp);
	fd[3] = dt_swap_a(stack, number, bp);
	fd[4] = dt_swap_b(stack, number, bp);
	fd[5] = dt_rrb(stack, number, bp);
	fd[6] = dt_rra(stack, number, bp);
	fd[7] = dt_push_a(stack, number, bp);
	return (fd);
}

void	do_min_fonc(t_stacks *stack, int idx)
{
	if (idx == 3)
		swap_a(stack, 1);
	else if (idx == 4)
		swap_b(stack, 1);
	else if (idx == 7)
		push_a(stack, 1);
	else if (idx == 0)
		push_b(stack, 1);
	else if (idx == 1)
		rotate_a(stack, 1);
	else if (idx == 2)
		rotate_b(stack, 1);
	else if (idx == 6)
		r_rotate_a(stack, 1);
	else
		r_rotate_b(stack, 1);
}

int	decision_tree(t_stacks *stack, int number, int bp)
{
	int	fb;
	int	idx;
	int	*fonc;

	fb = feed_back(stack);
	if (!fb || number <= 0)
		return (fb);
	fonc = min_algo(stack, number - 1, bp);
	idx = min(fonc);
	if (idx > 8)
		return (-1);
	fb = fonc[idx];
	free(fonc);
	if (number == bp)
		do_min_fonc(stack, idx);
	return (fb);
}
