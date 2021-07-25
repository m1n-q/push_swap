/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:16:52 by mishin            #+#    #+#             */
/*   Updated: 2021/07/23 23:17:17 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(char c, t_set *stack)
{
	char	*msg;

	if (c == 'a')
	{
		swap_top(stack->a);
		msg = "a\n";
	}
	else if (c == 'b')
	{
		swap_top(stack->b);
		msg = "b\n";
	}
	else if (c == 's')
	{
		swap_top(stack->a);
		swap_top(stack->b);
		msg = "s\n";
	}
	ft_putstr_fd("s", 1);
	ft_putstr_fd(msg, 1);
}

void	rr(char c, t_set *stack)
{
	char	*msg;

	if (c == 'a')
	{
		reverse_rotate(stack->a);
		msg = "a\n";
	}
	else if (c == 'b')
	{
		reverse_rotate(stack->b);
		msg = "b\n";
	}
	else if (c == 'r')
	{
		reverse_rotate(stack->a);
		reverse_rotate(stack->b);
		msg = "r\n";
	}
	ft_putstr_fd("rr", 1);
	ft_putstr_fd(msg, 1);
}

void	r(char c, t_set *stack)
{
	char	*msg;

	if (c == 'a')
	{
		rotate(stack->a);
		msg = "a\n";
	}
	else if (c == 'b')
	{
		rotate(stack->b);
		msg = "b\n";
	}
	else if (c == 'r')
	{
		rotate(stack->a);
		rotate(stack->b);
		msg = "r\n";
	}
	ft_putstr_fd("r", 1);
	ft_putstr_fd(msg, 1);
}

void	p(char c, t_set *stack)
{
	char	*msg;

	if (c == 'a')
	{
		stack_to_stack(stack->a, stack->b);
		msg = "a\n";
	}
	else if (c == 'b')
	{
		stack_to_stack(stack->b, stack->a);
		msg = "b\n";
	}
	ft_putstr_fd("p", 1);
	ft_putstr_fd(msg, 1);
}
