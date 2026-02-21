/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:31:39 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:12:21 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_op(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->top->data;
	a->top->data = a->top->next->data;
	a->top->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb_op(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->top->data;
	b->top->data = b->top->next->data;
	b->top->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss_op(t_stack *a, t_stack *b)
{
	sa_op(a);
	sb_op(b);
	write(1, "ss\n", 3);
}

void	pa_op(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !b || !b->top)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb_op(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !b || !a->top)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	write(1, "pb\n", 3);
}
