/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subproblem_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:23:43 by mishin            #+#    #+#             */
/*   Updated: 2021/07/24 15:15:39 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	size3_a_case1(t_set *stack)
{
	s('a', stack);
	p('b', stack);
	s('a', stack);
	p('a', stack);
	s('a', stack);
}

static inline void	size3_a_case2(t_set *stack)
{
	p('b', stack);
	s('a', stack);
	p('a', stack);
	s('a', stack);
}

static inline void	size3_a_case3(t_set *stack)
{
	s('a', stack);
	p('b', stack);
	s('a', stack);
	p('a', stack);
}

static inline void	size3_a(t_set *stack)
{
	if (stack->a->data[stack->a->top - 2] < stack->a->data[stack->a->top - 1] \
	&& stack->a->data[stack->a->top - 1] < stack->a->data[stack->a->top])
		size3_a_case1(stack);
	else if \
	(stack->a->data[stack->a->top - 2] < stack->a->data[stack->a->top] \
	&& stack->a->data[stack->a->top] < stack->a->data[stack->a->top - 1])
		size3_a_case2(stack);
	else if \
	(stack->a->data[stack->a->top - 1] < stack->a->data[stack->a->top - 2] \
	&& stack->a->data[stack->a->top - 2] < stack->a->data[stack->a->top])
		size3_a_case3(stack);
	else if \
	(stack->a->data[stack->a->top - 1] < stack->a->data[stack->a->top] \
	&& stack->a->data[stack->a->top] < stack->a->data[stack->a->top - 2])
		s('a', stack);
	else if (stack->a->data[stack->a->top] < stack->a->data[stack->a->top - 2] \
	&& stack->a->data[stack->a->top - 2] < stack->a->data[stack->a->top - 1])
	{
		p('b', stack);
		s('a', stack);
		p('a', stack);
	}
}

int	subproblem_a(t_set *stack, int sub_size)
{
	if (sub_size < 1)
		return (0);
	if (sub_size == 2)
	{
		if (stack->a->data[stack->a->top] > stack->a->data[stack->a->top - 1])
			s('a', stack);
		return (0);
	}
	else if (sub_size == 3)
		size3_a(stack);
	return (0);
}
