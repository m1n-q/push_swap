/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/12 12:24:54 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define A 1
# define B -1
# define PRT print_all(stack_a, stack_b);
# define DEBUG printf("upper_idx = (%d), lower_idx = (%d)\n\
pivot = %lld\n", upper_idx,lower_idx,pivot_val);

void	sort_b_using_a(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, long long pivot_val)
{
	int			sub_size;
	int			pivot_idx;
	long long	upper_val;
	t_move_info	upper_to_top;

	
	char tmp;
	while (scanf("%c",&tmp) && tmp != '\n');
	sub_size = upper_idx - lower_idx + 1;

	
	// if (stack_a->top < 0)
	// 	return;
	if (sub_size <= 1)
		return ;
	if (sub_size == 2)
	{
		if (stack_b->data[upper_idx] < stack_b->data[lower_idx])
			swap_data2(stack_a, stack_b, upper_idx, lower_idx);
		return ;
	}
	
	if (sub_size == 3)
	{
		sort_three_elems_rev(stack_a, stack_b, upper_idx, lower_idx);
		return ;
	}

	// pivot_idx = get_median_index(stack_b, upper_idx, lower_idx);
	// pivot_val = stack_b->data[pivot_idx];
	upper_val = stack_b->data[upper_idx];
	

	
	DEBUG
	printf("sorting B . . .\n");
	printf("초기상태\n");
	PRT
	/* 
		큰 값을 A 로 보내기, 단, subproblem 의 경계까지만
		(sub_size)
	*/

	int	rotated_while_find_large = 0;
	int	poped_while_find_large = 0;
	int	i = 0;

	while (i++ < sub_size)
	{
		if (stack_b->data[stack_b->top] > pivot_val)
		{
			pa;
			poped_while_find_large++;			
		}

		else
		{	
			rb;
			rotated_while_find_large++;
		}
	}
	
	/* 
		stack_B 의 회전상태 복구
		(sub_size)
	*/

	while (rotated_while_find_large--)			
	{	
		
		rrb;
		if (stack_b->data[stack_b->top] == pivot_val)	
			pa;		// 복구하면서 피벗 찾아서 A로 보내기
	}






/******************************************************************************/

	/*
		B의 상단에, 피벗보다 작은 부분만 남음.
		B 에 보냈던 피벗, 큰값 다시 가져오기?
		우짜지. 회전해서 upper_idx 를 top 으로 끌고오는 연산 없이
		정렬해보자.
	*/

	
	printf("다음 재귀 진행 전\n");
	PRT

	pivot_idx = get_median_index(stack_b, stack_b->top, lower_idx);
	pivot_val = stack_b->data[pivot_idx];
	sort_b_using_a(stack_a, stack_b, stack_b->top, lower_idx, pivot_val);
	sort_a_using_b(stack_a, stack_b, stack_a->top, 
				stack_a->top - poped_while_find_large + 1, 
				stack_a->data[
					get_median_index(
						stack_a, stack_a->top, 
						stack_a->top - poped_while_find_large + 1)] 
					);
	printf("재귀 빠져나온 후\n");
	PRT
	i = 0;
	while (i++ <= poped_while_find_large)
		pb;

	printf("A 에 넘겼던 것들 B로 돌림. 종료\n");
	PRT
	// sort_b_using_a(stack_a, stack_b, pivot_idx - 1, lower_idx);
	

}





void	sort_a_using_b(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, long long pivot_val)
{
	int			sub_size;
	int			pivot_idx;
	long long	upper_val;
	t_move_info	upper_to_top;
	
	
	char tmp;
	while (scanf("%c",&tmp) && tmp != '\n');
	
	
	
	sub_size = upper_idx - lower_idx + 1;
	if (sub_size <= 1)
		return ;
	if (sub_size == 2)
	{
		if (stack_a->data[upper_idx] > stack_a->data[lower_idx])
			swap_data(stack_a, stack_b, upper_idx, lower_idx);
		return ;
	}
		
	DEBUG
	printf("sorting A . . .\n");
/******************************************************************************/
	/* 
		작은 값을 B 로 보내기, 단, subproblem 의 경계까지만
		(sub_size)
	*/

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
	
	/* 
		stack_a 의 회전상태 복구
		(sub_size)
	*/

	while (rotated_while_find_small--)			
	{	
		rra;	
		if (stack_a->data[stack_a->top] == pivot_val)	
			pb;		// 복구하면서 피벗 찾아서 B로 보내기
	}
	PRT
/******************************************************************************/


		
	pivot_idx = get_median_index(stack_a, stack_a->top, 0);
	pivot_val = stack_a->data[pivot_idx];
	sort_a_using_b(stack_a, stack_b, stack_a->top, 0, pivot_val);		// subprob 의 윗부분을 다 넘긴 상태임. ( 작은 부분 )

	PRT
	sort_b_using_a(stack_a, stack_b, stack_b->top, 0, stack_b->data[get_median_index(stack_b, stack_b->top, 0)]);
	

	PRT
	//stack_b->top - poped_while_find_small
	i = 0;
	while (i++ <= poped_while_find_small)					// 이 부분만 빼고 B에서도 정렬..?	// 돌아오는 애들,, 은 작은놈들, 정렬이 안되어있을것임.
		pa;

	PRT
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
	
	// quick_sort_alpha(stack_a, stack_b, stack_a->top, 0,  0);
	// print_all(stack_a, stack_b);
	sort_a_using_b(stack_a, stack_b, stack_a->top, 0, stack_a->data[get_median_index(stack_a, stack_a->top, 0)]);
	print_all(stack_a, stack_b);
	// print_all(stack_a, stack_b);
	// sort_b_using_a(stack_a, stack_b, stack_b->top, 45);
	// print_all(stack_a, stack_b);
	// sort_beta(stack_a, stack_b);
	// insertion_sort(stack_a, stack_b);
	
}







