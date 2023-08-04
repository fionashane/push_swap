/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:05:01 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:09:11 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_r(t_stack **stack, int x, char c)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (x == 0 && c == 'a')
		write(1, "ra\n", 3);
	if (x == 0 && c == 'b')
		write(1, "rb\n", 3);
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_s(t_stack **stack, int x, char c)
{
	t_stack	*temp;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (x == 0 && c == 'a')
		write(1, "sa\n", 3);
	if (x == 0 && c == 'b')
		write(1, "sb\n", 3);
}

// pa (push a): Take the first element at the top of b and
// put it at the top of a.
// Do nothing if b is empty.
void	ft_p(t_stack **from, t_stack **to, int x, char c)
{
	t_stack	*temp;

	if (!*to)
		return ;
	temp = *from;
	*from = *to;
	*to = (*to)->next;
	(*from)->next = temp;
	if (x == 0 && c == 'a')
		write(1, "pa\n", 3);
	if (x == 0 && c == 'b')
		write(1, "pb\n", 3);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_rrs(t_stack **stack, int x, char c)
{
	t_stack	*temp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (x == 0 && c == 'a')
		write(1, "rra\n", 4);
	if (x == 0 && c == 'b')
		write(1, "rrb\n", 4);
}
