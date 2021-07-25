/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:20:51 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 12:45:10 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTE: REMOVE print_all
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "type.h"

# define OVER_INTEGER -2222222222LL
# define EMPTY -3333333333LL
# define NON_NUMERIC -4444444444LL

/* init, exit */
void				init(t_set *stack, t_ll_handler *ll);
void				clear_all(t_set *stack, t_ll **head);
void				error(t_set *stack, t_ll **head);
void				init_count(t_count *count);

/* linked list */
t_ll				*ll_new(long long data);
void				ll_push(t_ll **head, t_ll *new);
int					ll_clear(t_ll **head);

/* input */
int					input_to_ll(t_ll_handler *ll, char *arg);
void				ll_to_stack(t_ll **head, t_stack *stack);
int					check_dup(t_ll **head);

/* stack */
int					init_stack(t_set *set, int size);
void				push(t_stack *stack, long long val);
long long			pop(t_stack *stack);
int					clear_stack_set(t_set *stack);

/* operation */
void				swap_top(t_stack *stack);
void				stack_to_stack(t_stack *to, t_stack *from);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

/* command */
void				rr(char c, t_set *stack);
void				r(char c, t_set *stack);
void				s(char c, t_set *stack);
void				p(char c, t_set *stack);

/* index */
int					get_index(t_stack *stack, long long val);
int					get_median_index(long long *data, int top, int bottom);
t_pivot_info		get_pivot_info(t_stack *stack, \
								int upper_idx, int lower_idx);

/* sort */
int					partitioning_a(t_set *stack, int upper_idx, int lower_idx);
int					partitioning_b(t_set *stack, int upper_idx, int lower_idx);

/* subproblem */
int					subproblem_a(t_set *stack, int sub_size);
int					subproblem_b(t_set *stack, int sub_size);

/* search utils */
int					only_large_remained(t_stack *stack, long long pivot_val, \
										int size, t_count *count);
int					only_small_remained(t_stack *stack, long long pivot_val, \
										int size, t_count *count);
void				restore_a(t_set *stack, t_count *count);
void				restore_b(t_set *stack, t_count *count);

/* search a, b */
void				send_to_b(t_set *stack, t_pivot_info pivot, \
							int size, t_count *count);
void				send_to_a(t_set *stack, t_pivot_info pivot, \
							int size, t_count *count);

/* few arg */
int					processing_few_arg(t_set *stack);

/* utils */
void				ft_putstr_fd(char *s, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				my_qsort(long long *arr, int start, int end);
#endif
