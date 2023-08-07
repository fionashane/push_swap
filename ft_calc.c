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

// Calculates best rotation to use before pushing elements from stack "from" to stack "to"
int	ft_calc(t_stack *from, t_stack *to, char c)
{
	int		i;
	t_stack	*temp;

	temp = from;
	i = ft_case_rrarrb(from, to, from->num);
	while (temp)
	{
		if (i > ft_case_rarb(from, to, temp->num))
			i = ft_case_rarb(from, to, temp->num);
		if (i > ft_case_rrarrb(from, to, temp->num))
			i = ft_case_rrarrb(from, to, temp->num);
		if (i > ft_case_rarrb(from, to, temp->num, c))
			i = ft_case_rarrb(from, to, temp->num, c);
		if (i > ft_case_rrarb(from, to, temp->num, c))
			i = ft_case_rrarb(from, to, temp->num, c);
		temp = temp->next;
	}
	return (i);
}

// Converts string to long int
long int	ft_atol(const char *str)
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
			ft_error_message();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error_message();
	return (mod * i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
