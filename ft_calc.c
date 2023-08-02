#include "push_swap.h"

// Calculates best rotation to use before pushing elements from b to a
int	ft_calc_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_case_rrarrb_a(a, b, b->num);
	while (temp)
	{
        if (i > ft_case_rarb_a(a, b, temp->num))
            i = ft_case_rarb_a(a, b, temp->num);
        if (i > ft_case_rrarrb_a(a, b, temp->num))
            i = ft_case_rrarrb_a(a, b, temp->num);
        if (i > ft_case_rarrb_a(a, b, temp->num))
            i = ft_case_rarrb_a(a, b, temp->num);
        if (i > ft_case_rrarb_a(a, b, temp->num))
            i = ft_case_rrarb_a(a, b, temp->num);
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
	i = ft_case_rrarrb_b(a, b, a->num);
	while (temp)
    {
        if (i > ft_case_rarb_b(a, b, temp->num))
            i = ft_case_rarb_b(a, b, temp->num);
        if (i > ft_case_rrarrb_b(a, b, temp->num))
            i = ft_case_rrarrb_b(a, b, temp->num);
        if (i > ft_case_rarrb_b(a, b, temp->num))
            i = ft_case_rarrb_b(a, b, temp->num);
        if (i > ft_case_rrarb_b(a, b, temp->num))
            i = ft_case_rrarb_b(a, b, temp->num);
        temp = temp->next;
    }
	return (i);
}

// Converts string to long long int
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