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