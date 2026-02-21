/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:33:43 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:36:41 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*creating_node(int data)
{
	t_node	*n1;

	n1 = malloc(sizeof(t_node));
	if (!n1)
		return (NULL);
	n1->data = data;
	n1->index = 0;
	n1->next = NULL;
	return (n1);
}

void	fill_arr(int *arr, char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		arr[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
}

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
		return (0);
	init_stack(*a);
	init_stack(*b);
	return (1);
}

int	setup(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	*arr;

	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	fill_arr(arr, argv, argc);
	if (!checking_all(argv, argc, arr))
		return (0);
	if (!init_stacks(a, b))
		return (0);
	filling(*a, argc, arr);
	assign_index(*a, arr, argc - 1);
	free(arr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!setup(argc, argv, &a, &b))
		return (0);
	if (a->size >= 6)
		radix_sort(&a, &b);
	else if (a->size > 1)
		mini_sort(&a, &b);
	ft_lstclear(a->top);
	ft_lstclear(b->top);
	free(a);
	free(b);
	return (0);
}
