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

// Finds which index num_push should be if it gets pushed to stack.
int	ft_find_place(t_stack *stack, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push < stack->num && num_push > ft_lstlast(stack)->num)
		i = 0;
	else if (num_push > ft_find_max(stack) || num_push < ft_find_min(stack))
		i = ft_find_index(stack, ft_find_min(stack));
	else
	{
		temp = stack->next;
		while (stack->num > num_push || temp->num < num_push)
		{
			stack = stack->next;
			temp = stack->next;
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
