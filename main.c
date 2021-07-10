/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/10 13:37:52 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define A 0
# define B 1
# define PRT print_all(stack_a, stack_b);
# define DEBUG printf("upper_idx = (%d), lower_idx = (%d)\n\
pivot = (%d)%lld, depth = %d\n", upper_idx,lower_idx,pivot_idx,pivot_val, depth);

// void	quick_sort_beta(t_stack *stack_a,  t_stack *stack_b, int top, int bottom, int depth)
// {
// 	int			pivot_idx;
// 	int			pivot_idx_in_b;
// 	long long	pivot;
// 	int			count;
// 	int			size;
// 	int			direction;
// 	long long	org_top;
// 	int			org_top_idx;

// 	if (depth == 2)
// 		return ;
// 	size = top - bottom + 1;
// 	if (size <= 1)
// 		return ;
// 	if (size == 2)
// 	{
// 		if (stack_a->data[top] > stack_a->data[bottom])
// 			swap_data3(stack_a, stack_b, top, bottom);
// 		return ;
// 	}

// 	if (size == 3)
// 	{
// 		sort_three_elems(stack_a, stack_b, top, bottom);
// 		return ;
// 	}
	
// 	pivot_idx = get_median_index(stack_a, top, bottom);
// 	pivot = stack_a->data[pivot_idx];
	
// 	int i = 0;
// 	while (stack_a->top >= 0)
// 		pb;

// 	int tmp = stack_b->top;
// 	count = 0;
// 	while (count <= tmp)
// 	{
// 		if (stack_b->data[stack_b->top] > pivot)
// 			pa;
// 		else
// 			rb;
// 		count++;
// 	}
// 	pivot_idx_in_b = get_index(stack_b, pivot);
// 	org_top = stack_b->data[stack_b->top];
// 	direction = get_direction(stack_b, pivot_idx_in_b);
// 	while (stack_b->data[stack_b->top] != pivot)
// 	{	
// 		if (direction == R)
// 			rb;
// 		else
// 			rrb;
// 	}
// 	pa;
// 	org_top_idx = get_index(stack_b, org_top);
// 	if (org_top_idx != -1)
// 	{
// 		direction = get_direction(stack_b, org_top_idx);
// 		while (stack_b->data[stack_b->top] != org_top)
// 		{
// 			if (direction == R)
// 				rb;
// 			else
// 				rrb;
// 		}
// 	}
// 	while (stack_b->top >= 0)
// 		pa;
// 	quick_sort_beta(stack_a, stack_b, get_index(stack_a, pivot) - 1,bottom, depth + 1);
// 	quick_sort_beta(stack_a, stack_b, top, get_index(stack_a, pivot) + 1, depth + 1);
// 	print_all(stack_a, stack_b);
// }




void	quick_sort_beta(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, int depth)
{
	int			pivot_idx;
	int			pivot_idx_in_b;
	long long	pivot_val;
	int			count;
	int			sub_size;
	int			direction;
	long long	org_top;
	int			org_top_idx;
	long long	upper_val;

	if (depth == 5)
		return ;
	sub_size = upper_idx - lower_idx + 1;
	if (sub_size <= 1)
		return ;
	if (sub_size == 2)
	{
		if (stack_a->data[upper_idx] > stack_a->data[lower_idx])
			swap_data3(stack_a, stack_b, upper_idx, lower_idx);
		return ;
	}

	if (sub_size == 3)
	{
		sort_three_elems(stack_a, stack_b, upper_idx, lower_idx);
		return ;
	}
	
	pivot_idx = get_median_index(stack_a, upper_idx, lower_idx);
	pivot_val = stack_a->data[pivot_idx];
	upper_val = stack_a->data[upper_idx];
	
	DEBUG
	/* 이번 레벨의 upper bound 를 스택의 탑으로 보낸다 */
	int moved_upper_to_top = 0;
	while (stack_a->data[stack_a->top] != upper_val)
	{	
		ra;
		moved_upper_to_top++;
	}
	printf("AFTER_UPPER_TO_TOP\n");
	PRT

	/* 작은 값을 B 로 보내기, 단, subproblem 의 경계까지만 */
	int	rotated_while_find_small = 0;
	int	poped_while_find_small = 0;
	int	i = 0;
	while (i++ < sub_size)			
	{
		if (stack_a->data[stack_a->top] < pivot_val)
		{
			pb;
			poped_while_find_small++;
		}
		else
		{	
			ra;
			rotated_while_find_small++;
		}
	}
	/* stack_a 의 회전상태 복구 */
	while (rotated_while_find_small--)
		rra;

	printf("AFTER_SMALL_TO_B\n");
	PRT
	
	/* pivot 찾아서 B로 보내기 */
	int	rotated_while_find_pivot = 0;
	i = 0;
	printf("~ %d\n", (sub_size - poped_while_find_small));
	while (stack_a->top >= 0 && i++ < (sub_size - poped_while_find_small))	// subproblem의 경계가 줄어든 만큼, 반영해주기.
	{
		if (stack_a->data[stack_a->top] == pivot_val)
			pb;
		else
		{	
			ra;
			rotated_while_find_pivot++;
		}
	}
	/* stack_a 의 회전상태 복구 */
	while (rotated_while_find_pivot--)
		rra;
	printf("AFTER_PIVOT_TO_B\n");
	PRT
	
	/* 큰 값 찾아서 B로 보내기 */
	int	rotated_while_find_large = 0;
	int	poped_while_find_large = 0;
	i = 0;
	printf("~ %d\n", sub_size - poped_while_find_small - poped_while_find_large - 1);
	while (stack_a->top >= 0 && i++ < (sub_size - poped_while_find_small - 1))
	{	// i 값은 커지면서 subsize 만 줄어들면 안되지!
		if (stack_a->data[stack_a->top] > pivot_val)
		{	
			pb;
			poped_while_find_large++;
		}
		else
		{
			ra;
			rotated_while_find_large++;
		}
		printf("~ %d\n", sub_size - poped_while_find_small - poped_while_find_large - 1);
	}

	/* stack_a 의 회전상태 복구 */
	while (rotated_while_find_large--)
		rra;
	printf("AFTER_LARGE_TO_B\n");
	PRT

	/**** subproblem 부분 제외한 stack_a는 원상태 ? ****/
	/**** subproblem 의 pivot 위치 확보. 이제 다시 분할 가능 ****/
	i = 0;
	while (i++ < poped_while_find_small + poped_while_find_large + 1)
		pa;
	printf("AFTER_B_TO_A\n");
	PRT
	pivot_idx = get_index(stack_a, pivot_val);
	quick_sort_beta(stack_a, stack_b, upper_idx, pivot_idx + 1, depth + 1);
	quick_sort_beta(stack_a, stack_b, pivot_idx - 1, lower_idx, depth + 1);


	// (6) ~ (0) --> (8) ~ (0)    ?!!!?!!
}










void	sort_beta(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top >= 0)
	{
		if (stack_b->top == -1)
			pb;
		if (stack_a->data[stack_a->top] > stack_b->data[stack_b->top])
			pb;
		else
		{
			pa;
			sa;
		}
	}
	while (stack_b->top >= 0)
		pa;
}



int	main(int argc, char **argv)
{
	int			i;
	long long	is_int;
	t_stack		*stack_a;
	t_stack		*stack_b;
	
	i = argc;
	if (argc < 2)
		return 1;
	if ((stack_a = init_stack(argc - 1)) == NULL)
		return 2;
	if ((stack_b = init_stack(argc - 1)) == NULL)
		return 2;
	while (--i > 0)
	{	
		if ((is_int = ft_atoi(argv[i])) == OVER_INTEGER)
			return 3;
		else
			push(stack_a, is_int);
	}
	
	print_all(stack_a, stack_b);
	quick_sort_beta(stack_a, stack_b, stack_a->top, 0, 0);
	
	// sort_beta(stack_a, stack_b);

	print_all(stack_a, stack_b);
}