/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:25:05 by mishin            #+#    #+#             */
/*   Updated: 2021/07/10 02:42:17 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> //remove!!!!!!!!!!!!!!!!!!!!!!!!!!!

t_stack *init_stack(int size)
{
	t_stack	*new;
	int		i;

	if (size < 1)
		return (NULL);

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);

	if (!(new->data = (long long *)malloc(size * sizeof(long long))))
		return (NULL);

	i = -1;
	while (++i < size)
		new->data[i] = EMPTY;
	new->top = -1;
	new->size = size;
	return (new);
}

void print_all(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	printf("_______________________\n");
	i = stack_a->size;
	while (--i >= 0)
	{
		if (stack_a->data[i] != EMPTY && stack_b->data[i] != EMPTY)
			printf("(%d)\t%lld\t%lld\n",i, stack_a->data[i], stack_b->data[i]);
		else if (stack_a->data[i] == EMPTY && stack_b->data[i] != EMPTY)
			printf("(%d)\t\t%lld\n",i, stack_b->data[i]);
		else if (stack_a->data[i] != EMPTY && stack_b->data[i] == EMPTY)
			printf("(%d)\t%lld\n", i, stack_a->data[i]);
	}
	printf("_\t\t_\n");
	printf("a\t\tb\n");
	printf("_______________________\n");
}

void push(t_stack *stack, long long newdata)
{
	if (stack->top == stack->size - 1)
	{
		printf("Stack is full.\n");
		return ;
	}

	stack->top++;
	stack->data[stack->top] = newdata;
}

long long	pop(t_stack *stack)
{
	long long	ret;

	if (stack->top == -1)
	{
		printf("Stack is empty.\n");
		ret = EMPTY;
	}

	else
	{
		ret = stack->data[stack->top];
		stack->data[stack->top] = EMPTY;
		stack->top--;
	}

	return ret;
}