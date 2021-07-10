/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:20:51 by mishin            #+#    #+#             */
/*   Updated: 2021/07/10 04:07:27 by mishin           ###   ########.fr       */
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



# define sa swap_top(stack_a, "sa\n")
# define sb swap_top(stack_b, "sb\n")

# define pa stack_to_stack(stack_b, stack_a, "pa\n")
# define pb stack_to_stack(stack_a, stack_b, "pb\n")

# define ra rotate(stack_a, "ra\n")
# define rb rotate(stack_b, "rb\n")

# define rra reverse_rotate(stack_a, "rra\n")
# define rrb reverse_rotate(stack_b, "rrb\n")




t_stack		*init_stack(int size);
long long	ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);

void print_all(t_stack*, t_stack*);
void push(t_stack*, long long);
long long pop(t_stack*);


void	swap_top(t_stack *stack, char *msg);
void	stack_to_stack(t_stack *from, t_stack *to, char *msg);
void	rotate(t_stack *stack, char *msg);
void	reverse_rotate(t_stack *stack, char *msg);
size_t	ft_strlen(const char *s);


int		get_median_index(t_stack *stack, int top, int bottom);
void	swap_data3(t_stack *stack_a, t_stack *stack_b, int i, int j);
void	sort_three_elems(t_stack *stack_a, t_stack *stack_b, int top, int bottom);
int	get_direction(t_stack *stack, int to_be_top);
int	get_index(t_stack *stack, long long value);
void	sort_three_elems_rev(t_stack *stack_a, t_stack *stack_b, int top, int bottom);
void	quick_sort_alpha(t_stack *stack_a,  t_stack *stack_b, int top, int bottom, int depth);
#endif