#include "push_swap.h"

// Rotates a and rotates b
int	ft_move_rarb(t_stack **a, t_stack **b, int x, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != x && ft_find_place_b(*b, x) > 0)
			ft_rr(a, b, 0);
		while ((*a)->num != x)
			ft_r(a, 0, 'a');
		while (ft_find_place_b(*b, x) > 0)
			ft_r(b, 0, 'b');
		ft_p(b, a, 0, 'b');
	}
	else
	{
		while ((*b)->num != x && ft_find_place_a(*a, x) > 0)
			ft_rr(a, b, 0);
		while ((*b)->num != x)
			ft_r(b, 0, 'b');
		while (ft_find_place_a(*a, x) > 0)
			ft_r(a, 0, 'a');
		ft_p(a, b, 0, 'a');
	}
	return (-1);
}

// Reverse rotates a and reverse rotates b
int	ft_move_rrarrb(t_stack **a, t_stack **b, int x, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != x && ft_find_place_b(*b, x) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->num != x)
			ft_rrs(a, 0, 'a');
		while (ft_find_place_b(*b, x) > 0)
			ft_rrs(b, 0, 'b');
		ft_p(b, a, 0, 'b');
	}
	else
	{
		while ((*b)->num != x && ft_find_place_a(*a, x) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->num != x)
			ft_rrs(b, 0, 'b');
		while (ft_find_place_a(*a, x) > 0)
			ft_rrs(a, 0, 'a');
		ft_p(a, b, 0, 'a');
	}
	return (-1);
}

// Reverse rotates a and rotates b
int	ft_move_rrarb(t_stack **a, t_stack **b, int x, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != x)
			ft_rrs(a, 0, 'a');
		while (ft_find_place_b(*b, x) > 0)
			ft_r(b, 0, 'b');
		ft_p(b, a, 0, 'b');
	}
	else
	{
		while (ft_find_place_a(*a, x) > 0)
			ft_rrs(a, 0, 'a');
		while ((*b)->num != x)
			ft_r(b, 0, 'b');
		ft_p(a, b, 0, 'a');
	}
	return (-1);
}

// Rotates a and reverse rotates b
int	ft_move_rarrb(t_stack **a, t_stack **b, int x, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != x)
			ft_r(a, 0, 'a');
		while (ft_find_place_b(*b, x) > 0)
			ft_rrs(b, 0, 'b');
		ft_p(b, a, 0, 'b');
	}
	else
	{
		while (ft_find_place_a(*a, x) > 0)
			ft_r(a, 0, 'a');
		while ((*b)->num != x)
			ft_rrs(b, 0, 'b');
		ft_p(a, b, 0, 'a');
	}
	return (-1);
}