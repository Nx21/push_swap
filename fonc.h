/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:36:03 by nhanafi           #+#    #+#             */
/*   Updated: 2022/04/26 13:01:45 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONC_H
# define FONC_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				size;
	int				len_a;
	int				len_b;
}	t_stacks;

t_stacks	*stacks_make(const char **list, int len);
void		swap_a(t_stacks *stack, int cas);
void		swap_b(t_stacks *stack, int cas);
void		swap_ab(t_stacks *stack, int cas);
void		push_a(t_stacks *stack, int st);
void		push_b(t_stacks *stack, int st);
void		rotate_a(t_stacks *stack, int cas);
void		r_rotate_a(t_stacks *stack, int cas);
void		r_rotate_b(t_stacks *stack, int cas);
void		rotate_b(t_stacks *stack, int cas);
void		rotate_ab(t_stacks *stack, int cas);
void		r_rotate_ab(t_stacks *stack, int cas);
void		free_stack(t_stack *head);
void		error_head(t_stack *head);
void		free_all(t_stacks *stack);
void		error_checker(t_stacks *stack, char *step);
int			feed_back(t_stacks *stack);
int			add_number(long number, t_stack **head, int neg);
void		ft_atois(const char *str, t_stack **head, int *j);
void		str_to_int(const char *str, t_stack **head);
#endif