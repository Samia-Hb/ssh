/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:47:46 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/23 23:41:14 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_BONUS_H
# define PUSH_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

typedef struct t_stack
{
	int				data;
	int				index;
	struct t_stack	*next;
}	t_stack;

void	sa(t_stack *stackA);
void	sb(t_stack *stackB);
void	pa(t_stack **stackA, t_stack **stackB);
void	pb(t_stack **stackA, t_stack **stackB);
void	ra(t_stack **stackA);
void	rb(t_stack **stackB);
void	rr(t_stack **stackA, t_stack **stackB);
void	rra(t_stack **stackA);
void	rrb(t_stack **stackB);
void	rrr(t_stack **stackA, t_stack **stackB);
void	push(t_stack **stackA, int data);
t_stack	*pop(t_stack **stack_s);

int		ft_lstsize(t_stack *lst);
char	**ft_split(char const *s, char c);
long	*check_arguments(int argc, char **argv);
int		check_type(char **tab);
int		check_duplicate(long *arr, int argc, char **argv);
int		nbr_of_arguments(int argc, char **argv);
int		ft_strlen(const char *str);
int		ft_counter(char const *str, char c);
long	ft_atoi(char *str);
int		check_all(int argc, char **argv);
////
//void	printstack(t_stack *stack);
int		is_stack_sorted(t_stack *s, int element);
void	fill_the_stack(int argc, char **argv, t_stack **stackA);
int		ft_strcmp(char *s1, char *s2);

#endif
