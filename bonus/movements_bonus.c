/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:09:42 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/19 15:54:35 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_bonus.h"

void	sa(t_stack *stackA)//it works
{
	int		tmp;
	t_stack	*courant;

	courant = stackA->next;
	tmp = stackA->data;
	stackA->data = courant->data;
	courant->data = tmp;
}

void	sb(t_stack *stackB)//it works
{
	int		tmp;
	t_stack	*courant;

	courant = stackB->next;
	tmp = stackB->data;
	stackB->data = courant->data;
	courant->data = tmp;
}

void	pa(t_stack **stackA, t_stack **stackB)//it works
{
	t_stack	*courant;

	if (ft_lstsize(*stackB) > 0)
	{
		courant = pop(stackB);
		courant->next = *stackA;
		*stackA = courant;
	}
}

void	pb(t_stack **stackA, t_stack **stackB)//it works
{
	t_stack	*courant;

	if (ft_lstsize(*stackA) > 0)
	{
		courant = pop(stackA);
		courant->next = *stackB;
		*stackB = courant;
	}
}

void	ra(t_stack **stackA)//it works
{
	t_stack	*last;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	while (last->next != NULL)
		last = last->next;
	last->next = *stackA;
	*stackA = (*stackA)->next;
	last->next->next = NULL;
}
