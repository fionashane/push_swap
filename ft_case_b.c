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
int	ft_case_rarb_b(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = ft_find_place_b(b, x);
	if (i < ft_find_index(a, x))
		i = ft_find_index(a, x);
	return (i);
}

// Calculates the total number of moves when rra and rrb is used.
int	ft_case_rrarrb_b(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, x))
		i = ft_lstsize(b) - ft_find_place_b(b, x);
	if ((i < (ft_lstsize(a) - ft_find_index(a, x))) && ft_find_index(a, x))
		i = ft_lstsize(a) - ft_find_index(a, x);
	return (i);
}

// Calculates the total number of moves when rra and rb is used.
int	ft_case_rrarb_b(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_index(a, x))
		i = ft_lstsize(a) - ft_find_index(a, x);
	i += ft_find_place_b(b, x);
	return (i);
}

// Calculates the total number of moves when ra and rrb is used.
int	ft_case_rarrb_b(t_stack *a, t_stack *b, int x)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, x))
		i = ft_lstsize(b) - ft_find_place_b(b, x);
	i += ft_find_index(a, x);
	return (i);
}
