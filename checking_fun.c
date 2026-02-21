/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalfoqha <oalfoqha@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 04:21:38 by oalfoqha          #+#    #+#             */
/*   Updated: 2026/02/21 04:55:48 by oalfoqha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_num(char**argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(is_num(argv[i][j])))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checking_dup(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_num(char y)
{
	if (!(y >= '0' && y <= '9') && y != '-' && y != '+')
		return (0);
	return (1);
}

int	checking_all(char**argv, int argc, int *arr)
{
	if (!checking_num(argv) || !checking_dup(argv, argc))
	{
		free(arr);
		return (0);
	}
	if (!checking_max_min(argv))
	{
		free(arr);
		return (0);
	}
	if (is_sorted(arr, argc - 1))
	{
		free(arr);
		return (0);
	}
	return (1);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
