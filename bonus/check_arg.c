/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:20 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/23 23:02:05 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	check_type(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] < 48 || tab[i][j] > 57)
			{
				if (tab[i][0] != '-' && tab[i][0] != '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(long *arr, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < nbr_of_arguments(argc, argv) - 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		j = i + 1;
		while (j < nbr_of_arguments(argc, argv))
		{
			if (arr[i] == arr[j] || arr[j] > INT_MAX || arr[j] < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	*check_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	long	*arr;

	i = 1;
	j = 0;
	arr = malloc(nbr_of_arguments(argc, argv));
	if (!arr)
		return (0);
	while (i < argc)
	{
		if (ft_counter(argv[i], ' ') == 0)
			return (0);
		tab = ft_split(argv[i], ' ');
		if (!check_type(tab))
			return (0);
		k = 0;
		while (tab[k])
			arr[j++] = ft_atoi(tab[k++]);
		i++;
	}
	return (arr);
}

int	check(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_counter(argv[i], ' ') == 0 || ft_strlen(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return (1);
}

int	check_all(int argc, char **argv)
{
	long	*arr;

	check(argv);
	if (nbr_of_arguments(argc, argv) == 1)
	{
		if (ft_atoi(argv[1]) > INT_MAX || ft_atoi(argv[1]) < INT_MIN)
			write(1, "Error\n", 6);
		exit(1);
	}
	arr = check_arguments(argc, argv);
	if (!arr || !check_duplicate(arr, argc, argv))
	{
		write(1, "Error\n", 6);
		free(arr);
		return (0);
	}
	free(arr);
	return (1);
}
