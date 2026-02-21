/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:47:14 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:42:57 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

long	ft_atoi(const char *str);
void	ft_lstclear(t_node *lst);
int		is_num(char c);
int		checking_num(char **argv);
int		checking_dup(char **argv, int argc);
int		isempty(t_stack *s);
int		checking_max_min(char **argv);
t_node	*creating_node(int data);
void	sa_op(t_stack *a);
void	sb_op(t_stack *b);
void	ss_op(t_stack *a, t_stack *b);
void	pa_op(t_stack *a, t_stack *b);
void	pb_op(t_stack *a, t_stack *b);
void	ra_op(t_stack *a);
void	rb_op(t_stack *b);
void	rr_op(t_stack *a, t_stack *b);
void	rra_op(t_stack *a);
void	rrb_op(t_stack *b);
void	rrr_op(t_stack *a, t_stack *b);
void	radix_sort(t_stack **a, t_stack **b);
void	mini_sort(t_stack **a, t_stack **b);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
int		ft_lstsize(t_stack *lst);
int		checking_all(char**argv, int argc, int *arr);
int		is_sorted(int *arr, int size);
void	filling(t_stack *a, int argc, int *arr);
void	assign_index(t_stack *a, int *arr, int size);
void	print_stack(t_stack *s);
void	give_index(t_stack *a);
void	switch_values(t_stack *a);
void	do_radix_sort(t_stack **a, t_stack **b);
int		find_max_bits(t_stack *a);
void	radix_sort(t_stack **a, t_stack **b);
int		init_stacks(t_stack **a, t_stack **b);
void	init_stack(t_stack *a);
void	fill_arr(int *arr, char **argv, int argc);
int		setup(int argc, char **argv, t_stack **a, t_stack **b);
#endif