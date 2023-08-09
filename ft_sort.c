/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:27:15 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:27:38 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts stack_a if there are only 2 elements
// Sorts stack_b (calls ft_sort_b)
// Sorts stack_a (calls ft_sort_a)
// Sorts stack_a if minimum number is not yet at top of stack
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_s(stack_a, 0, 'a');
	else if (ft_lstsize(*stack_a) > 2 && ft_check_sorted((*stack_a)->next))
		ft_s(stack_a, 0, 'a');
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_find_min(*stack_a))
				ft_r(stack_a, 0, 'a');
		}
		else
		{
			while ((*stack_a)->num != ft_find_min(*stack_a))
				ft_rrs(stack_a, 0, 'a');
		}
	}
}

// Pushes snd sorts elements to b until only 3 elements are left in a
// Sorts elements in a when 3 elements left
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_p(&stack_b, stack_a, 0, 'b');
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_p(&stack_b, stack_a, 0, 'b');
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_sort_bmore(stack_a, &stack_b);
	if (!ft_check_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

// Calculates the least number of moves and pushes elements from a to b
void	ft_sort_bmore(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
	{
		temp = *stack_a;
		i = ft_calc_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, temp->num, 'a'))
				i = ft_move_rarb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, temp->num, 'a'))
				i = ft_move_rrarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, temp->num, 'a'))
				i = ft_move_rarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, temp->num, 'a'))
				i = ft_move_rrarb(stack_a, stack_b, temp->num, 'a');
			else
				temp = temp->next;
		}
	}
}

// Sorts stack elements when 3 elements left
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_find_min(*stack_a) == (*stack_a)->num)
	{
		ft_rrs(stack_a, 0, 'a');
		ft_s(stack_a, 0, 'a');
	}
	else if (ft_find_max(*stack_a) == (*stack_a)->num)
	{
		ft_r(stack_a, 0, 'a');
		if (!ft_check_sorted(*stack_a))
			ft_s(stack_a, 0, 'a');
	}
	else
	{
		if (ft_find_index(*stack_a, ft_find_max(*stack_a)) == 1)
			ft_rrs(stack_a, 0, 'a');
		else
			ft_s(stack_a, 0, 'a');
	}
}

// Calculates the least number of moves and pushes elements from b to a
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_calc_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, temp->num, 'b'))
				i = ft_move_rarb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, temp->num, 'b'))
				i = ft_move_rarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, temp->num, 'b'))
				i = ft_move_rrarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, temp->num, 'b'))
				i = ft_move_rrarb(stack_a, stack_b, temp->num, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}
