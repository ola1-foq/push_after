/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:28:09 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/20 21:44:28 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_stack *a)
{
	t_node	*temp;
	t_node	*temp2;
	int		index;

	if (!a || !a->top)
		return ;
	temp2 = a->top;
	while (temp2)
	{
		index = 0;
		temp = a->top;
		while (temp)
		{
			if (temp->data < temp2->data)
				index++;
			temp = temp->next;
		}
		temp2->index = index;
		temp2 = temp2->next;
	}
}

void	switch_values(t_stack *a)
{
	t_node	*temp;

	if (!a || !a->top)
		return ;
	temp = a->top;
	while (temp)
	{
		temp->data = temp->index;
		temp = temp->next;
	}
}

int	find_max_bits(t_stack *a)
{
	t_node	*temp;
	int		max;
	int		x;

	if (!a || !a->top)
		return (0);
	temp = a->top;
	max = temp->data;
	x = 0;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	while (max >> x)
		x++;
	return (x);
}

void	do_radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	x;
	int	y;
	int	size;

	max_bits = find_max_bits(*a);
	x = 0;
	size = (*a)->size;
	while (x < max_bits)
	{
		y = 0;
		while (y < size)
		{
			if ((*a)->top && (((*a)->top->data >> x) & 1) == 1)
				ra_op(*a);
			else if ((*a)->top)
				pb_op(*a, *b);
			y++;
		}
		while (*b && (*b)->size > 0)
			pa_op(*a, *b);
		x++;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		return ;
	give_index(*a);
	switch_values(*a);
	do_radix_sort(a, b);
}
