/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:16:42 by mishin            #+#    #+#             */
/*   Updated: 2021/09/03 11:13:10 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	send_small_part_to_b(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('b', stack);
	p('b', stack);
	count->pop.small++;
	return (1);
}

static inline int	send_mid_part_to_b(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('b', stack);
	p('b', stack);
	count->rotation.mid++;
	count->pop.mid++;
	return (2);
}

static inline int	skip_large_part(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('r', stack);
	else
		r('a', stack);
	count->rotation.small++;
	return (3);
}

void	send_to_b(t_set *stack, t_pivot_info pivot, \
							int size, t_count *count)
{
	int	i;
	int	last;

	last = 0;
	i = -1;
	while (++i < size)
	{
		if (stack->a->data[stack->a->top] <= pivot.val.p1)
			last = send_small_part_to_b(stack, count, last);
		else if (stack->a->data[stack->a->top] <= pivot.val.p2)
			last = send_mid_part_to_b(stack, count, last);
		else
		{
			if (only_large_remained(stack->a, pivot.val.p2, size, count))
				break ;
			last = skip_large_part(stack, count, last);
		}
	}
	if (last == 2)
		r('b', stack);
	restore_a(stack, count);
}
