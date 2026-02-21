/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 04:14:03 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:33:01 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}

void	ft_lstclear(t_node *lst)
{
	t_node	*node;
	t_node	*tmp;

	node = lst;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	lst = NULL;
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (lst)
	{
		tmp = lst->top;
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	filling(t_stack *a, int argc, int *arr)
{
	int		i;
	t_node	*node;

	i = argc - 2;
	while (i >= 0)
	{
		node = creating_node(arr[i]);
		if (!node)
			return ;
		node->next = a->top;
		a->top = node;
		a->size++;
		i--;
	}
}
