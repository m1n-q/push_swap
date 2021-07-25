/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:01:12 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 01:20:35 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_count(t_count *count)
{
	count->pop.small = 0;
	count->pop.mid = 0;
	count->pop.large = 0;
	count->rotation.small = 0;
	count->rotation.mid = 0;
	count->rotation.large = 0;
}

void	init(t_set *stack, t_ll_handler *ll)
{
	ll->head = NULL;
	ll->size = 0;
	stack->a = NULL;
	stack->b = NULL;
}

void	clear_all(t_set *stack, t_ll **head)
{
	clear_stack_set(stack);
	ll_clear(head);
}

void	error(t_set *stack, t_ll **head)
{
	ft_putstr_fd("Error\n", 2);
	clear_all(stack, head);
	exit(1);
}
