/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:18:12 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:19:24 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the total number of moves when ra and rb is used.
int	ft_case_rarb_a(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = ft_find_place_a(a, x);
	if (i < ft_find_index(b, x))
		i = ft_find_index(b, x);
	return (i);
}

// Calculates the total number of moves when rra and rrb is used.
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, x))
		i = ft_lstsize(a) - ft_find_place_a(a, x);
	if ((i < (ft_lstsize(b) - ft_find_index(b, x))) && ft_find_index(b, x))
		i = ft_lstsize(b) - ft_find_index(b, x);
	return (i);
}

// Calculates the total number of moves when ra and rrb is used.
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_index(b, x))
		i = ft_lstsize(b) - ft_find_index(b, x);
	i += ft_find_place_a(a, x);
	return (i);
}

// Calculates the total number of moves when rra and rb is used.
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, x))
		i = ft_lstsize(a) - ft_find_place_a(a, x);
	i += ft_find_index(b, x);
	return (i);
}
