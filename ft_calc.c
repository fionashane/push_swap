/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:21 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:18:00 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates best rotation to use before pushing elements from b to a
int	ft_calc_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_case_rrarrb(a, b, b->num, 'b');
	while (temp)
	{
		if (i > ft_case_rarb(a, b, temp->num, 'b'))
			i = ft_case_rarb(a, b, temp->num, 'b');
		if (i > ft_case_rrarrb(a, b, temp->num, 'b'))
			i = ft_case_rrarrb(a, b, temp->num, 'b');
		if (i > ft_case_rarrb(a, b, temp->num, 'b'))
			i = ft_case_rarrb(a, b, temp->num, 'b');
		if (i > ft_case_rrarb(a, b, temp->num, 'b'))
			i = ft_case_rrarb(a, b, temp->num, 'b');
		temp = temp->next;
	}
	return (i);
}

// Calculates best rotation to use before pushing elements from a to b
int	ft_calc_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = ft_case_rrarrb(a, b, a->num, 'a');
	while (temp)
	{
		if (i > ft_case_rarb(a, b, temp->num, 'a'))
			i = ft_case_rarb(a, b, temp->num, 'a');
		if (i > ft_case_rrarrb(a, b, temp->num, 'a'))
			i = ft_case_rrarrb(a, b, temp->num, 'a');
		if (i > ft_case_rarrb(a, b, temp->num, 'a'))
			i = ft_case_rarrb(a, b, temp->num, 'a');
		if (i > ft_case_rrarb(a, b, temp->num, 'a'))
			i = ft_case_rrarb(a, b, temp->num, 'a');
		temp = temp->next;
	}
	return (i);
}

// Converts string to long int
long int	ft_atol(const char *str, t_stack **stack)
{
	int			mod;
	long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error_message(stack);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error_message(stack);
	return (mod * i);
}
