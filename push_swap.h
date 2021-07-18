/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:20:51 by mishin            #+#    #+#             */
/*   Updated: 2021/07/17 23:54:40 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
# include "type.h"
						# include <stdio.h>

# define OVER_INTEGER -2222222222LL
# define EMPTY -3333333333LL



# define sa swap_top(stack->a, "sa\n")
# define sb swap_top(stack->b, "sb\n")

# define pa stack_to_stack(stack->b, stack->a, "pa\n")
# define pb stack_to_stack(stack->a, stack->b, "pb\n")

# define ra rotate(stack->a, "ra\n")
# define rb rotate(stack->b, "rb\n")

# define rra reverse_rotate(stack->a, "rra\n")
# define rrb reverse_rotate(stack->b, "rrb\n")




t_stack		*init_stack(int size);
long long	ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);

void		print_all(t_set *stack);
void		push(t_stack *stack, long long val);
long long	pop(t_stack *stack);


void		swap_top(t_stack *stack, char *msg);
void		stack_to_stack(t_stack *from, t_stack *to, char *msg);
void		rotate(t_stack *stack, char *msg);
void		reverse_rotate(t_stack *stack, char *msg);
size_t		ft_strlen(const char *s);


int		get_median_index(t_stack *stack, int top, int bottom);
void	swap_data(t_stack *stack_a, t_stack *stack_b, int i, int j);
void	sort_three_elems(t_stack *stack_a, t_stack *stack_b, int top, int bottom);
int		get_direction(t_stack *stack, int to_be_top);
int		get_index(t_stack *stack, long long value);
void	sort_three_elems_rev(t_stack *stack_a, t_stack *stack_b, int top, int bottom);
void	quick_sort_alpha(t_stack *stack_a,  t_stack *stack_b, int top, int bottom, int depth);

void	swap_data_tmp(t_stack *stack_a, t_stack *stack_b, int i, int j);
void	insert(t_stack *stack_a, t_stack *stack_b, int idx, int target_idx);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b);

void	sort_alpha(t_stack *stack_a, t_stack *stack_b);
void	sort_beta(t_stack *stack_a, t_stack *stack_b);
void	swap_data2(t_stack *stack_a, t_stack *stack_b, int i, int j);

int		sort_a_using_b(t_set *stack, int upper_idx, int lower_idx, long long pivot_val, int depth);
int		sort_b_using_a(t_set *stack, int upper_idx, int lower_idx, long long pivot_val, int depth);

int		is_asc(t_stack *stack, int upper_idx, int lower_idx);
int		is_desc(t_stack *stack, int upper_idx, int lower_idx);



t_vector_idx	get_dual_pivot(t_stack *stack, int upper_idx, int lower_idx);

int	dual_qsort_a(t_set *stack, int upper_idx, int lower_idx);
int	dual_qsort_b(t_set *stack, int upper_idx, int lower_idx);
#endif
