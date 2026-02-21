/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:56:00 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:13:09 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_op(t_stack *b)
{
	t_node	*tmp;
	t_node	*u;

	if (isempty(b))
		return ;
	tmp = b->top;
	u = b->top;
	while (u->next)
		u = u->next;
	b->top = tmp->next;
	u->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ra_op(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rr_op(t_stack *a, t_stack *b)
{
	if (isempty(b) || isempty(a))
		return ;
	ra_op(a);
	rb_op(b);
	write(1, "rr\n", 3);
}
