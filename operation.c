/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:15:26 by mishin            #+#    #+#             */
/*   Updated: 2021/07/11 03:06:34 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	swap_top(t_stack *stack, char *msg)				// O(n1
{
	long long	fir;
	long long	sec;
	
	fir = pop(stack);
	if (fir == EMPTY)
		return ;
	sec = pop(stack);
	if (sec == EMPTY)
		return ;
	push(stack, fir);
	push(stack, sec);
	printf("%s", msg);
}

void	stack_to_stack(t_stack *from, t_stack *to, char *msg)		// O(1)
{
	long long	data;

	if ((data = pop(from)) == EMPTY)
		return ;
	push(to, data);
	printf("%s", msg);
}

void	rotate(t_stack *stack, char *msg)							// O(n)
{
	long long	tmp;
	int			i;

	if (stack->top == -1)
		return ;
	i = stack->top;
	tmp = stack->data[stack->top];
	while (--i >= 0)
		stack->data[i + 1] = stack->data[i];
	stack->data[0] = tmp;
	printf("%s", msg);
}

void 	reverse_rotate(t_stack *stack, char *msg)				// O(n)
{
	long long	tmp;
	int			i;

	if (stack->top == -1)
		return ;
	i = -1;
	tmp = stack->data[0];
	while (++i < stack->top)
		stack->data[i] = stack->data[i + 1];
	stack->data[stack->top] = tmp;
	printf("%s", msg);
}
