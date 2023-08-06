/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:19:42 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:20:54 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the total number of moves when ra and rb is used.
int	ft_case_rarb(t_stack *from, t_stack *to, int x)
{
	int	i;

	i = ft_find_place(to, x);
	if (i < ft_find_index(from, x))
		i = ft_find_index(from, x);
	return (i);
}

// Calculates the total number of moves when ra and rrb is used.
int	ft_case_rarrb(t_stack *from, t_stack *to, int x)
{
	int	i;

	i = 0;
	if (ft_find_index(from, x))
		i = ft_lstsize(from) - ft_find_index(from, x);
	i += ft_find_place(to, x);
	return (i);
}

// Calculates the total number of moves when rra and rb is used.
int	ft_case_rrarb(t_stack *from, t_stack *to, int x)
{
	int	i;

	i = 0;
	if (ft_find_place(to, x))
		i = ft_lstsize(to) - ft_find_place(to, x);
	i += ft_find_index(from, x);
	return (i);
}

// Calculates the total number of moves when rra and rrb is used.
int	ft_case_rrarrb(t_stack *from, t_stack *to, int x)
{
	int	i;

	i = 0;
	if (ft_find_place(to, x))
		i = ft_lstsize(to) - ft_find_place(to, x);
	if ((i < (ft_lstsize(from) - ft_find_index(from, x))) && ft_find_index(from, x))
		i = ft_lstsize(from) - ft_find_index(from, x);
	return (i);
}