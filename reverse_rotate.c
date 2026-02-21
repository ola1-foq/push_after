/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:24:04 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 01:57:41 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_op(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

void	rrb_op(t_stack *b)
{
	t_node	*prev;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	prev = NULL;
	last = b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}

void	rrr_op(t_stack *a, t_stack *b)
{
	if (isempty(b) || isempty(a))
		return ;
	rra_op(a);
	rrb_op(b);
	write(1, "rrr\n", 4);
}
