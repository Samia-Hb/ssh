/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:49 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/28 00:16:50 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stackA, int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		ft_printf("Allocation Failure");
		return ;
	}
	node -> data = data;
	node -> next = *stackA;
	*stackA = node;
}

t_stack	*pop(t_stack **stack_s)
{
	t_stack	*tmp;
	t_stack	*courant;

	tmp = *stack_s;
	courant = (*stack_s)-> next;
	tmp -> data = (*stack_s)-> data;
	*stack_s = courant;
	return (tmp);
}

void	sort_stacka(t_stack **stackA)
{
	int	min;

	min = min_element(*stackA);
	while (pos(*stackA, min) != 0)
	{
		if (pos(*stackA, min) <= ft_lstsize(*stackA) / 2)
		{
			ra(stackA);
			ft_printf("ra\n");
		}
		else if (pos(*stackA, min) > ft_lstsize(*stackA) / 2)
		{
			rra(stackA);
			ft_printf("rra\n");
		}
	}
}

void	fill_the_stack(int argc, char **argv, t_stack **stackA)
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
void clean_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_all(argc, argv))
		return (0);
	else
		fill_the_stack(argc, argv, &stack_a);
	if (is_stack_sorted(stack_a, 0))
	{
		clean_stack(stack_a);
		return (0);
	}
	else if (ft_lstsize(stack_a) == 5)
		sort_five_element(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 3)
		sort_three_element(&stack_a);
	else
		push_half_to_stackb(&stack_a, &stack_b);
	if (!is_stack_sorted(stack_a, 0))
		sort_stacka(&stack_a);
	clean_stack(stack_a);
	return (0);
}
