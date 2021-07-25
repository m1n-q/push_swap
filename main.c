/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 10:18:07 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: TESTER

int	main(int argc, char **argv)
{
	t_ll_handler	ll;
	t_set			stack;
	int				i;

	init(&stack, &ll);
	i = 0;
	if (argc < 2)
		error(&stack, &(ll.head));
	while (++i < argc)
		if (input_to_ll(&ll, argv[i]) == -1)
			error(&stack, &(ll.head));
	if (check_dup(&(ll.head)) == -1)
		error(&stack, &(ll.head));
	if ((init_stack(&stack, ll.size)) == -1)
		error(&stack, &(ll.head));
	ll_to_stack(&(ll.head), stack.a);
	if (stack.a->size == 3 || stack.a->size == 5)
	{
		if (processing_few_arg(&stack) == -1)
			error(&stack, &(ll.head));
	}
	else if (partitioning_a(&stack, stack.a->top, 0) == -1)
		error(&stack, &(ll.head));
	clear_all(&stack, &(ll.head));
}
