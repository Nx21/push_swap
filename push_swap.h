/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:46:07 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 12:39:24 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "fonc.h"

int		decision_tree(t_stacks *stack, int number, int bp);
int		dt_swap_a(t_stacks *stack, int number, int bp);
int		dt_swap_b(t_stacks *stack, int number, int bp);
int		dt_swap_s(t_stacks *stack, int number, int bp);
int		dt_push_a(t_stacks *stack, int number, int bp);
int		dt_push_b(t_stacks *stack, int number, int bp);
int		dt_ra(t_stacks *stack, int number, int bp);
int		dt_rb(t_stacks *stack, int number, int bp);
int		dt_rra(t_stacks *stack, int number, int bp);
int		dt_rrb(t_stacks *stack, int number, int bp);
int		*min_algo(t_stacks *stack, int number, int bp);
void	sort_b(t_stacks *stack, int num, int avg);
int		find(int num, t_stacks *stack);
int		sort_rest(t_stacks *stack);
void	quick_sort(t_stacks *stack);
#endif
