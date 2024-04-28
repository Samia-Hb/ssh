/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:29:58 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/23 00:08:07 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	nbr_of_arguments(int argc, char **argv)//done
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += ft_counter(argv[i], ' ');
		i++;
	}
	return (count);
}

void	check_mov(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(*stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else
	{
		write(1, "Error..\n", 8);
		exit(1);
	}
}

void	check_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (str[0] == '\n')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	check_mov(stack_a, stack_b, str);
}

void	fill_the_stack(int argc, char **argv, t_stack **stackA)//done
{
	long	*arr;
	int		size;

	size = nbr_of_arguments(argc, argv);
	arr = check_arguments(argc, argv);
	while (size > 0)
	{
		push(stackA, arr[size - 1]);
		size--;
	}
	free(arr);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_all(argc, argv))
		return (0);
	else
		fill_the_stack(argc, argv, &stack_a);
	if (is_stack_sorted(stack_a, 0))
		return (0);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		check_input(str, &stack_a, &stack_b);
		free(str);
	}
	if (is_stack_sorted(stack_a, 0) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
