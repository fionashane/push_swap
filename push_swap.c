/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:31:04 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/09 16:11:01 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialise stack a
// If stack a is empty or there are duplicate inputs, print error message
// If stack a is not sorted, start the sorting algorithm
int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac <= 1)
		return (0);
	a = ft_init_stack(ac, av);
	if (!a || ft_check_dup(a))
	{
		ft_free_stack(&a);
		ft_error_message();
	}
	if (!ft_check_sorted(a))
		ft_sort(&a);
	ft_free_stack(&a);
	return (0);
}

// If argument count is less than 2, print error message
// If argument count is equal to 2, split the quoted string to numbers 
// If argument count is more than 2, convert the strings to integers 
// Add elements to stack a
t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error_message();
	if (ac == 2)
		a = ft_split_quoted(av);
	else
	{
		while (i < ac)
		{
			j = ft_atol(av[i]);
			ft_add_node(&a, ft_init_node(j));
			i++;
		}
	}
	if (!a)
		ft_free_stack(&a);
	return (a);
}

// Split the quoted string to generate stack of integers
// Spaces(ascii 32) are the separator
t_stack	*ft_split_quoted(char **av)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(av[1], 32);
	while (temp[i])
	{
		j = ft_atol(temp[i]);
		ft_add_node(&a, ft_init_node(j));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (a);
}

// Initialises node
t_stack	*ft_init_node(int number)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error_message();
	new->num = number;
	new->next = NULL;
	return (new);
}

// Adds node to the stack
void	ft_add_node(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(ft_lstlast(*stack))->next = new_node;
}
