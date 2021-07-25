/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:53:33 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 12:37:58 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	send_large_part_to_a(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('a', stack);
	p('a', stack);
	count->pop.large++;
	return (1);
}

static inline int	send_mid_part_to_a(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('a', stack);
	p('a', stack);
	count->rotation.mid++;
	count->pop.mid++;
	return (2);
}

static inline int	skip_small_part(t_set *stack, t_count *count, int last)
{
	if (last == 2)
		r('r', stack);
	else
		r('b', stack);
	count->rotation.large++;
	return (3);
}

void	send_to_a(t_set *stack, t_pivot_info pivot, \
							int size, t_count *count)
{
	int	i;
	int	last;

	last = 0;
	i = -1;
	while (++i < size)
	{
		if (stack->b->data[stack->b->top] >= pivot.val.p2)
			last = send_large_part_to_a(stack, count, last);
		else if (stack->b->data[stack->b->top] >= pivot.val.p1)
			last = send_mid_part_to_a(stack, count, last);
		else
		{
			if (only_small_remained(stack->b, pivot.val.p1, size, count))
				break ;
			last = skip_small_part(stack, count, last);
		}
	}
	if (last == 2)
		r('a', stack);
	restore_b(stack, count);
}
