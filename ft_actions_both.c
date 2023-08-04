/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:57:16 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/04 14:04:43 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rr : ra and rb at the same time
void	ft_rr(t_stack **a, t_stack **b, int c)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ft_r(a, 1, 'a');
	ft_r(b, 1, 'b');
	if (c == 0)
		write(1, "rr\n", 3);
}

// rrr : rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b, int x)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ft_rrs(a, 1, 'a');
	ft_rrs(b, 1, 'b');
	if (x == 0)
		write(1, "rrr\n", 4);
}

// ss : sa and sb at the same time.
void	ft_ss(t_stack **a, t_stack **b, int x)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ft_s(a, 1, 'a');
	ft_s(b, 1, 'b');
	if (x == 0)
		write(1, "ss\n", 3);
}
