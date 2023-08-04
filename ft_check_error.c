/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:21:41 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:21:43 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if there are duplicate elements
int	ft_check_dup(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->num == temp->num)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

// Checks if stack is sorted
int	ft_check_sorted(t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack)
	{
		if (i > stack->num)
			return (0);
		i = stack->num;
		stack = stack->next;
	}
	return (1);
}

// Prints error message
void	ft_error_message(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

// Frees the stack
void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		*stack = temp;
	}
}

// Frees the string
void	ft_free_str(char **str)
{
	char	*n1;

	if (!str)
		return ;
	while (*str)
	{
		n1 = *str;
		str++;
		free(n1);
	}
	*str = NULL;
}
