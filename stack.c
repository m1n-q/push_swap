/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:25:05 by mishin            #+#    #+#             */
/*   Updated: 2021/09/03 11:38:20 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->data)
		free(stack->data);
	free(stack);
	return ;
}

int	clear_stack_set(t_set *stack)
{
	clear_stack(stack->a);
	clear_stack(stack->b);
	return (-1);
}

int	init_stack(t_set *set, int size)
{
	int		i;

	if (size < 1)
		return (-1);
	set->a = (t_stack *)malloc(sizeof(t_stack));
	set->b = (t_stack *)malloc(sizeof(t_stack));
	if (!(set->a) || !(set->b))
		return (clear_stack_set(set));
	set->a->data = (long long *)malloc(size * sizeof(long long));
	set->b->data = (long long *)malloc(size * sizeof(long long));
	if (!(set->a->data) || !(set->b->data))
		return (clear_stack_set(set));
	i = -1;
	while (++i < size)
	{
		set->a->data[i] = EMPTY;
		set->b->data[i] = EMPTY;
	}
	set->a->top = -1;
	set->b->top = -1;
	set->a->size = size;
	set->b->size = size;
	return (0);
}

void	push(t_stack *stack, long long newdata)
{
	if (stack->top == stack->size - 1)
		return ;
	stack->top++;
	stack->data[stack->top] = newdata;
}

long long	pop(t_stack *stack)
{
	long long	ret;

	if (stack->top == -1)
		ret = EMPTY;
	else
	{
		ret = stack->data[stack->top];
		stack->data[stack->top] = EMPTY;
		stack->top--;
	}
	return (ret);
}
