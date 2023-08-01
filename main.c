#include "push_swap.h"

// Initialise stack a
// If stack a is empty or there are duplicate inputs, print error message
// If stack a is not sorted, start the sorting algorithm
int	main(int ac, char **av)
{
	t_stack	*a;

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

// Converts string to long long int
long int	ft_atol(const char *str)
{
	int				mod;
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
	return (a);
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

// Checks if there are duplicate elements
int	ft_check_dup(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->num == temp->num)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

// Checks if stack is sorted
int	ft_check_sorted(t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack)
	{
		if (i > stack->num)
			return (0);
		i = stack->num;
		stack = stack->next;
	}
	return (1);
}

// Prints error message
void	ft_error_message(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

// Frees the stack
void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		*stack = temp;
	}
}

// Frees the string
void	ft_free_str(char **str)
{
	char	*n1;

	if (!str)
		return ;
	while (*str)
	{
		n1 = *str;
		str++;
		free(n1);
	}
	*str = NULL;
}

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

// Calculates the least number of moves and pushes elements from a to b
void	ft_sort_bmore(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
	{
		temp = *stack_a;
		i = ft_calc_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_b(*stack_a, *stack_b, temp->num))
				i = ft_move_rarb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rrarrb_b(*stack_a, *stack_b, temp->num))
				i = ft_move_rrarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rarrb_b(*stack_a, *stack_b, temp->num))
				i = ft_move_rarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_case_rrarb_b(*stack_a, *stack_b, temp->num))
				i = ft_move_rrarb(stack_a, stack_b, temp->num, 'a');
			else
				temp = temp->next;
		}
	}
}

// Pushes snd sorts elements to b until only 3 elements are left in a
// Sorts elements in a when 3 elements left
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_p(&stack_b, stack_a, 0, 'b');
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_p(&stack_b, stack_a, 0, 'b');
	if (ft_lstsize(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_sort_bmore(stack_a, &stack_b);
	if (!ft_check_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

// Calculates the least number of moves and pushes elements from b to a
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_calc_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, temp->num))
				i = ft_move_rarb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, temp->num))
				i = ft_move_rarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, temp->num))
				i = ft_move_rrarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, temp->num))
				i = ft_move_rrarb(stack_a, stack_b, temp->num, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

// Sorts stack_a if there are only 2 elements
// Sorts stack_b (calls ft_sort_b)
// Sorts stack_a (calls ft_sort_a)
// Sorts stack_a if minimum number is not yet at top of stack
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_s(stack_a, 0, 'a');
	else if (ft_lstsize(*stack_a) > 2 && ft_check_sorted((*stack_a)->next))
		ft_s(stack_a, 0, 'a');
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_find_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_find_min(*stack_a))
				ft_r(stack_a, 0, 'a');
		}
		else
		{
			while ((*stack_a)->num != ft_find_min(*stack_a))
				ft_rrs(stack_a, 0, 'a');
		}			
	}	
}


// Sorts stack elements when 3 elements left
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_find_min(*stack_a) == (*stack_a)->num)
	{
		ft_rrs(stack_a, 0, 'a');
		ft_s(stack_a, 0, 'a');
	}
	else if (ft_find_max(*stack_a) == (*stack_a)->num)
	{
		ft_r(stack_a, 0, 'a');
		if (!ft_check_sorted(*stack_a))
			ft_s(stack_a, 0, 'a');
	}
	else
	{
		if (ft_find_index(*stack_a, ft_find_max(*stack_a)) == 1)
			ft_rrs(stack_a, 0, 'a');
		else
			ft_s(stack_a, 0, 'a');
	}
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

// Checks if character is a digit
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

// Returns size of string passed as parameter
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Copies a size of n characters from source to destination
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// Returns duplicate of string passed as parameter
char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	return ((char *)ft_memcpy(new, s, len));
}

// Copies certain number of characters from source to destination
// Returns the length of source after successful/unsuccessful copying
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

// Returns substring of a string passed as argument
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	sub_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	if (len > sub_len)
		len = sub_len;
	len += 1;
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len);
	return (dest);
}

// Count number of substrings if the input is a quoted string
int	ft_count_substrs(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

// Continuation of ft_split
void	ft_gen_splits(char const *s, char c, char **strs)
{
	char const	*s_tmp;
	char		**strs_tmp;

	s_tmp = s;
	strs_tmp = strs;
	while (*s_tmp)
	{
		while (*s == c)
			++s;
		s_tmp = s;
		while (*s_tmp && *s_tmp != c)
			++s_tmp;
		if (s_tmp > s || *s_tmp == c)
		{
			*strs_tmp = ft_substr(s, 0, s_tmp - s);
			s = s_tmp;
			++strs_tmp;
		}
	}
	*strs_tmp = NULL;
}

// Allocates memory for an array of strings
// If memory is successfully allocated, continue to actually splitting the quoted string of numbers
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;

	count = ft_count_substrs(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	ft_gen_splits(s, c, strs);
	return (strs);
}

// Finds stack index of element
int	ft_find_index(t_stack *stack, int num)
{
	int		i;

	i = 0;
	while (stack->num != num)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// Finds which index num_push should be if it gets pushed to b.
int	ft_find_place_b(t_stack *stack_b, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push > stack_b->num && num_push < ft_lstlast(stack_b)->num)
		i = 0;
	else if (num_push > ft_find_max(stack_b) || num_push < ft_find_min(stack_b))
		i = ft_find_index(stack_b, ft_find_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->num < num_push || temp->num > num_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// Finds which index num_push should be if it gets pushed to a.
int	ft_find_place_a(t_stack *stack_a, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push < stack_a->num && num_push > ft_lstlast(stack_a)->num)
		i = 0;
	else if (num_push > ft_find_max(stack_a) || num_push < ft_find_min(stack_a))
		i = ft_find_index(stack_a, ft_find_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->num > num_push || temp->num < num_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}

// Returns stack last element
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Returns stack size
int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// Finds minimum number in stack
int	ft_find_min(t_stack *stack)
{
	int		i;

	i = stack->num;
	while (stack)
	{
		if (stack->num < i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}

// Finds maximum number in stack
int	ft_find_max(t_stack *stack)
{
	int		i;

	i = stack->num;
	while (stack)
	{
		if (stack->num > i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}

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

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void ft_r(t_stack **stack, int x, char c)
{
    t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (x == 0 && c == 'a')
		write(1, "ra\n", 3);
    if (x == 0 && c == 'b')
		write(1, "rb\n", 3);
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_s(t_stack **stack, int x, char c)
{
	t_stack	*temp;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (x == 0 && c == 'a')
		write(1, "sa\n", 3);
    if (x == 0 && c == 'b')
		write(1, "sb\n", 3);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	ft_p(t_stack **from, t_stack **to, int x, char c)
{
	t_stack	*temp;

	if (!*to)
		return ;
	temp = *from;
	*from = *to;
	*to = (*to)->next;
	(*from)->next = temp;
	if (x == 0 && c == 'a')
		write(1, "pa\n", 3);
	if (x == 0 && c == 'b')
		write(1, "pb\n", 3);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_rrs(t_stack **stack, int x, char c)
{
	t_stack	*temp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (x == 0 && c == 'a')
		write(1, "rra\n", 4);
    if (x == 0 && c == 'b')
		write(1, "rrb\n", 4);
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
