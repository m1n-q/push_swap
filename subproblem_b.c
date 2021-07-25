/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subproblem_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:36:43 by mishin            #+#    #+#             */
/*   Updated: 2021/07/24 23:44:41 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	size3_b_case4(t_set *stack)
{
	p('a', stack);
	s('b', stack);
	p('a', stack);
	s('a', stack);
	p('a', stack);
}

static inline void	size3_b_case5(t_set *stack)
{
	s('b', stack);
	p('a', stack);
	s('b', stack);
	p('a', stack);
	s('a', stack);
	p('a', stack);
}

static inline void	size3_b_case6(t_set *stack)
{
	s('b', stack);
	p('a', stack);
	s('b', stack);
	p('a', stack);
	p('a', stack);
}

static inline void	size3_b(t_set *stack, int i)
{
	if (stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top] \
	&& stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1])
		s('b', stack);
	if (stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top - 1] \
	&& stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top])
		while (i--)
			p('a', stack);
	else if \
	(stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top - 2] \
	&& stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top])
	{
		p('a', stack);
		s('b', stack);
		p('a', stack);
		p('a', stack);
	}
	else if (stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top] \
	&& stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 2])
		size3_b_case4(stack);
	else if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1] \
	&& stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top - 2])
		size3_b_case5(stack);
	else if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 2] \
	&& stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top - 1])
		size3_b_case6(stack);
}

int	subproblem_b(t_set *stack, int sub_size)
{
	if (sub_size < 1)
		return (0);
	else if (sub_size == 1)
	{
		p('a', stack);
		return (0);
	}
	else if (sub_size == 2)
	{
		if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1])
			s('b', stack);
		p('a', stack);
		p('a', stack);
		return (0);
	}
	else if (sub_size == 3)
		size3_b(stack, 3);
	return (0);
}
