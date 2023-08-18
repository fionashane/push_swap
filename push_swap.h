/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:31:25 by fsalimba          #+#    #+#             */
/*   Updated: 2023/08/02 13:31:29 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			num;
	struct s_stack	*next;
}	t_stack;

t_stack		*ft_init_stack(int ac, char **av);
t_stack		*ft_split_quoted(char **av);
t_stack		*ft_init_node(int number);
void		ft_add_node(t_stack **stack, t_stack *new_node);

int			ft_check_dup(t_stack *stack);
int			ft_check_sorted(t_stack *stack);
void		ft_free_str(char **str);
void		ft_free_stack(t_stack **stack);
void		ft_error_message(t_stack **stack);

t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);

int			ft_find_min(t_stack *stack);
int			ft_find_max(t_stack *stack);
int			ft_find_index(t_stack *stack, int num);
int			ft_find_place_b(t_stack *b, int num_push);
int			ft_find_place_a(t_stack *a, int num_push);

void		ft_sort(t_stack **stack_a);
t_stack		*ft_sort_b(t_stack **stack_a);
void		ft_sort_bmore(t_stack **a, t_stack **b);
void		ft_sort_three(t_stack **stack_a);
t_stack		**ft_sort_a(t_stack **stack_a, t_stack **stack_b);

int			ft_calc_ab(t_stack *a, t_stack *b);
int			ft_calc_ba(t_stack *a, t_stack *b);
long int	ft_atol(const char *s, t_stack **stack);

int			ft_case_rarb(t_stack *a, t_stack *b, int x, char c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int x, char c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int x, char c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int x, char c);

int			ft_move_rarb(t_stack **a, t_stack **b, int x, char s);
int			ft_move_rrarrb(t_stack **a, t_stack **b, int x, char s);
int			ft_move_rrarb(t_stack **a, t_stack **b, int x, char s);
int			ft_move_rarrb(t_stack **a, t_stack **b, int x, char s);

void		ft_r(t_stack **stack, int x, char c);
void		ft_s(t_stack **stack, int x, char c);
void		ft_p(t_stack **stack1, t_stack **stack2, int x, char c);
void		ft_rrs(t_stack **stack, int x, char c);

void		ft_ss(t_stack **a, t_stack **b, int x);
void		ft_rr(t_stack **a, t_stack **b, int x);
void		ft_rrr(t_stack **a, t_stack **b, int x);

#endif
