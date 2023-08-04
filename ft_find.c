/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:24:43 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:24:45 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds stack index of element
int	ft_find_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->num != num)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// Finds which index num_push should be if it gets pushed to b.
int	ft_find_place_b(t_stack *stack_b, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push > stack_b->num && num_push < ft_lstlast(stack_b)->num)
		i = 0;
	else if (num_push > ft_find_max(stack_b) || num_push < ft_find_min(stack_b))
		i = ft_find_index(stack_b, ft_find_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->num < num_push || temp->num > num_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// Finds which index num_push should be if it gets pushed to a.
int	ft_find_place_a(t_stack *stack_a, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push < stack_a->num && num_push > ft_lstlast(stack_a)->num)
		i = 0;
	else if (num_push > ft_find_max(stack_a) || num_push < ft_find_min(stack_a))
		i = ft_find_index(stack_a, ft_find_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->num > num_push || temp->num < num_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}

// Finds minimum number in stack
int	ft_find_min(t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack)
	{
		if (stack->num < i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}

// Finds maximum number in stack
int	ft_find_max(t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack)
	{
		if (stack->num > i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}
