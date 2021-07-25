/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:25:38 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 12:46:08 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_large_remained(t_stack *stack, long long pivot_val, \
									int size, t_count *count)
{
	int	i;
	int	lower_idx;

	i = stack->top + 1;
	lower_idx = stack->top - (size - count->pop.small - count->pop.mid) + 1;
	while (--i >= lower_idx)
	{
		if (stack->data[i] <= pivot_val)
			return (0);
	}
	return (1);
}

int	only_small_remained(t_stack *stack, long long pivot_val, \
									int size, t_count *count)
{
	int	i;
	int	lower_idx;

	i = stack->top + 1;
	lower_idx = stack->top - (size - count->pop.large - count->pop.mid) + 1;
	while (--i >= lower_idx)
	{
		if (stack->data[i] >= pivot_val)
			return (0);
	}
	return (1);
}

void	restore_a(t_set *stack, t_count *count)
{
	while (count->rotation.mid > 0 && count->rotation.small > 0)
	{
		rr('r', stack);
		count->rotation.mid--;
		count->rotation.small--;
	}
	while (count->rotation.mid--)
		rr('b', stack);
	while (count->rotation.small--)
		rr('a', stack);
}

void	restore_b(t_set *stack, t_count *count)
{
	while (count->rotation.mid > 0 && count->rotation.large > 0)
	{
		rr('r', stack);
		count->rotation.mid--;
		count->rotation.large--;
	}
	while (count->rotation.mid--)
		rr('a', stack);
	while (count->rotation.large--)
		rr('b', stack);
}
