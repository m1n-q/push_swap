/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:27:24 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 12:45:20 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: NORMINETTE, LAST TRY

static int	asc(t_stack *stack, int upper_idx, int lower_idx)
{
	long long	max;
	int			i;

	max = stack->data[lower_idx];
	i = lower_idx - 1;
	while (++i <= upper_idx)
	{
		if (stack->data[i] < max)
			return (0);
		max = stack->data[i];
	}
	return (1);
}

static int	desc(t_stack *stack, int upper_idx, int lower_idx)
{
	long long	min;
	int			i;

	min = stack->data[lower_idx];
	i = lower_idx - 1;
	while (++i <= upper_idx)
	{
		if (stack->data[i] > min)
			return (0);
		min = stack->data[i];
	}
	return (1);
}

static int	pa_upto(int size, t_set *stack)
{
	int	i;

	i = -1;
	while (++i < size)
		p('a', stack);
	return (0);
}

int	partitioning_a(t_set *stack, int upper_idx, int lower_idx)
{
	t_pivot_info	pivot;
	t_count			count;
	int				size;

	init_count(&count);
	size = upper_idx - lower_idx + 1;
	if (desc(stack->a, stack->a->top, 0) && asc(stack->b, stack->b->top, 0))
		return (pa_upto(stack->b->top + 1, stack));
	if (upper_idx < 0 || lower_idx < 0 || desc(stack->a, upper_idx, lower_idx))
		return (0);
	if (size <= 3)
		return (subproblem_a(stack, size));
	pivot = get_pivot_info(stack->a, upper_idx, lower_idx);
	if (pivot.idx.p1 == -1 || pivot.idx.p2 == -1)
		return (-1);
	send_to_b(stack, pivot, size, &count);
	partitioning_a(stack, stack->a->top, \
				stack->a->top - (size - count.pop.mid - count.pop.small) + 1);
	partitioning_b(stack, stack->b->top, stack->b->top - count.pop.mid + 1);
	partitioning_b(stack, stack->b->top, stack->b->top - count.pop.small + 1);
	return (0);
}

int	partitioning_b(t_set *stack, int upper_idx, int lower_idx)
{
	t_pivot_info	pivot;
	t_count			count;
	int				size;

	init_count(&count);
	size = upper_idx - lower_idx + 1;
	if (upper_idx < 0 || lower_idx < 0)
		return (0);
	if (size <= 3)
		return (subproblem_b(stack, size));
	if (asc(stack->b, upper_idx, lower_idx))
		return (pa_upto(size, stack));
	pivot = get_pivot_info(stack->b, upper_idx, lower_idx);
	if (pivot.idx.p1 == -1 || pivot.idx.p2 == -1)
		return (-1);
	send_to_a(stack, pivot, size, &count);
	partitioning_a(stack, stack->a->top, \
				stack->a->top - (count.pop.large + count.pop.mid) + 1);
	partitioning_b(stack, stack->b->top, \
				stack->b->top - (size - count.pop.mid - count.pop.large) + 1);
	return (0);
}
