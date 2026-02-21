/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:43:49 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:55:52 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	a;
	int		sign;

	sign = 1;
	i = 0;
	a = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (a * sign);
}

int	checking_max_min(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	isempty(t_stack *s)
{
	if (s->size == 0)
		return (1);
	return (0);
}

void	assign_index(t_stack *a, int *arr, int size)
{
	t_node	*tmp;
	int		i;
	int		rank;

	tmp = a->top;
	while (tmp)
	{
		rank = 0;
		i = 0;
		while (i < size)
		{
			if (arr[i] < tmp->data)
				rank++;
			i++;
		}
		tmp->index = rank;
		tmp = tmp->next;
	}
}

void	init_stack(t_stack *a)
{
	a->top = NULL;
	a->size = 0;
}
