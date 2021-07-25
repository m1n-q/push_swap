/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:18:46 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 01:39:26 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg3(t_set *stack)
{
	if (stack->a->data[0] < stack->a->data[1] \
	&& stack->a->data[1] < stack->a->data[2])
	{
		s('a', stack);
		rr('a', stack);
	}
	else if (stack->a->data[0] < stack->a->data[2] \
			&& stack->a->data[2] < stack->a->data[1])
		rr('a', stack);
	else if (stack->a->data[1] < stack->a->data[0] \
			&& stack->a->data[0] < stack->a->data[2])
		r('a', stack);
	else if (stack->a->data[1] < stack->a->data[2] \
			&& stack->a->data[2] < stack->a->data[0])
		s('a', stack);
	else if (stack->a->data[2] < stack->a->data[0] \
			&& stack->a->data[0] < stack->a->data[1])
	{
		rr('a', stack);
		s('a', stack);
	}
}

static int	arg5(t_set *stack)
{
	long long	*arr;
	long long	pivot;
	int			i;

	arr = (long long *)malloc(sizeof(long long) * 5);
	if (!arr)
		return (-1);
	ft_memcpy(arr, stack->a->data, sizeof(long long) * 5);
	my_qsort(arr, 0, 4);
	pivot = arr[2];
	free(arr);
	i = -1;
	while (++i < 5)
	{
		if (stack->a->data[stack->a->top] < pivot)
			p('b', stack);
		else
			r('a', stack);
	}
	arg3(stack);
	if (stack->b->data[0] > stack->b->data[1])
		s('b', stack);
	p('a', stack);
	p('a', stack);
	return (0);
}

int	processing_few_arg(t_set *stack)
{
	if (stack->a->size == 3)
	{
		arg3(stack);
		return (0);
	}
	return (arg5(stack));
}
