/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/14 02:41:33 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


# define DEBUG printf("upper_idx = (%d), lower_idx = (%d)\n\
pivot = %lld\n", upper_idx,lower_idx,pivot_val);
# define PRT DEBUG print_all(stack_a, stack_b);







void	sort_b_using_a(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, long long pivot_val)
{
	int			sub_size;
	int			pivot_idx;

	
	// char tmp;
	// while (scanf("%c",&tmp) && tmp != '\n');
	
	
	if (upper_idx < 0 || lower_idx < 0 )
		return ;	

	
	printf("sorting B . . .\n");
	printf("초기상태\n");
	PRT
	



	// if (is_asc(stack_b))
	// 	return;


	sub_size = upper_idx - lower_idx + 1;
	if (sub_size <= 1)
		return ;
	
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
		sorting B 재귀를 끝내고 나면
		B의 상단에, 피벗보다 작은 부분 (띄엄띄엄...) 만 남음.
		A 에 보냈던 피벗, 큰값 다시 가져오기?
	*/

	
	printf("sorting_B : 다음 재귀 진행 전\n");
	PRT

	int			next_pivot_idx = get_median_index(stack_b, stack_b->top, lower_idx);
	long long	next_pivot_val = stack_b->data[next_pivot_idx];
	sort_b_using_a(stack_a, stack_b, stack_b->top, lower_idx, next_pivot_val);

	printf("sorting_B : 재귀(sorting B) 빠져나온 후\n");
	PRT

	sort_a_using_b(stack_a, stack_b, stack_a->top, stack_a->top - poped_while_find_large, stack_a->data[get_median_index(stack_a, stack_a->top, stack_a->top - poped_while_find_large)]);


	printf("sorting_B : 재귀(sorting A) 빠져나온 후\n");
	printf("넘겼던 개수 : %d\n", poped_while_find_large + 1);
	PRT
	i = 0;
	while (i++ <= poped_while_find_large)
		pb;

	printf("A 에 넘겼던 것들 B로 돌림. 종료\n");
	PRT

	

}





void	sort_a_using_b(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, long long pivot_val)
{
	int			sub_size;
	int			pivot_idx;

	
	
	// char tmp;
	// while (scanf("%c",&tmp) && tmp != '\n');
	
	
	
	if (is_desc(stack_a))
		return;


	if (upper_idx < 0 || lower_idx < 0 )
		return ;

	sub_size = upper_idx - lower_idx + 1;
	if (sub_size <= 1)
		return ;
		

	printf("sorting A . . .\n");
	printf("초기상태\n");
	PRT
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


		
	int			next_pivot_idx = get_median_index(stack_a, stack_a->top, 0);
	long long	next_pivot_val = stack_a->data[next_pivot_idx];
	
	
	sort_a_using_b(stack_a, stack_b, stack_a->top, lower_idx, next_pivot_val);		// subprob 의 윗부분을 다 넘긴 상태임. ( 작은 부분 )
	printf("sorting_A : 재귀(sorting a) 빠져나온 후\n");
	PRT
	
	sort_b_using_a(stack_a, stack_b, stack_b->top, stack_b->top - poped_while_find_small, stack_b->data[get_median_index(stack_b, stack_b->top, stack_b->top - poped_while_find_small)]);
	printf("sorting_A : 재귀(sorting B) 빠져나온 후\n");
	printf("넘겼던 개수 : %d\n", poped_while_find_small + 1);
	PRT
	
	i = 0;
	while (i++ <= poped_while_find_small)					// 	넘긴부분 다시 가져와야함. 근데 정렬을 해놓고 가져와야함.
		pa;
	printf("B 에 넘겼던 것들 A로 돌림. 종료\n");
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
	
	sort_a_using_b(stack_a, stack_b, stack_a->top, 0, stack_a->data[get_median_index(stack_a, stack_a->top, 0)]);
	// print_all(stack_a, stack_b);
	
	
	
}







