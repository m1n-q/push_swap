/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/18 17:41:52 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define DEBUG printf("upper_idx = (%d), lower_idx = (%d)\npivot = %lld\n<depth = %d>\n", upper_idx,lower_idx,pivot_val, depth);
# define PRT DEBUG print_all(stack);
# define PRT2 printf("upper_idx = (%d), lower_idx = (%d)\np1 = %lld, p2 = %lld\n", upper_idx,lower_idx, val.p1, val.p2); print_all(stack);

int	dual_qsort_a(t_set *stack, int upper_idx, int lower_idx)
{
	int	sub_size;
	int	rotated_while_find_small = 0;
	int	rotated_while_find_mid = 0;
	int	rotated_while_find_large = 0;
	int	poped_while_find_small = 0;
	int	poped_while_find_mid = 0;
	int	poped_while_find_large = 0;
	int	i;
	t_vector_val	val;
	t_vector_idx	idx;

	// printf("\n< SORTING A >\n");
	idx = get_dual_pivot(stack->a, upper_idx, lower_idx);
	val.p1 = stack->a->data[idx.l];
	val.p2 = stack->a->data[idx.r];


	// PRT2
	// char tmp;
	// while (scanf("%c",&tmp) && tmp != '\n');



	sub_size = upper_idx - lower_idx + 1;

	// if (sub_size < 3)
	// {
	// 	//sort;
	// 	return (0);
	// }

	if (is_desc(stack->a, stack->a->top, 0) && is_asc(stack->b, stack->b->top, 0))
	{
		while (stack->b->top >= 0)
			pa;
		return (-1);
	}




	if (sub_size < 1)
		return (0);

	if (upper_idx < 0 || lower_idx < 0)
		return (0);

	if (is_desc(stack->a, upper_idx, lower_idx))
		return (0);



/******************************************************************************/
	/*
		작은 값을 B 로 보내기
		O(sub_size)
	*/

	i = -1;
	while (++i < sub_size)
	{
		if (stack->a->data[stack->a->top] < val.p1)
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

	i = -1;
	while (++i < rotated_while_find_small)
	{
		rra;
		if (stack->a->data[stack->a->top] == val.p1)
		{
			pb;
			poped_while_find_small++;
		}
	}


/******************************************************************************/

	/*
		중간 값을 B 로 보내기
		O(sub_size)
	*/

	i = -1;
	while (++i < sub_size - poped_while_find_small)
	{
		if (stack->a->data[stack->a->top] < val.p2)
		{
			pb;
			poped_while_find_mid++;
		}
		else
		{
			ra;
			rotated_while_find_mid++;
		}
	}


	i = -1;
	while (++i < rotated_while_find_mid)
	{
		rra;
		if (stack->a->data[stack->a->top] == val.p2)
		{
			pb;
			poped_while_find_mid++;
		}
	}


/******************************************************************************/


	if (-1 == dual_qsort_a(stack, stack->a->top, stack->a->top - (sub_size - poped_while_find_mid - poped_while_find_small) + 1))
		return -1;
	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - poped_while_find_mid + 1))
		return -1;
	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - poped_while_find_small + 1))
		return -1;

/******************************************************************************/
	return (0);
}

int	dual_qsort_b(t_set *stack, int upper_idx, int lower_idx)
{
	int	sub_size;
	int	rotated_while_find_small = 0;
	int	rotated_while_find_mid = 0;
	int	rotated_while_find_large = 0;
	int	poped_while_find_small = 0;
	int	poped_while_find_mid = 0;
	int	poped_while_find_large = 0;
	int	i;
	t_vector_val	val;
	t_vector_idx	idx;

	// printf("\n< SORTING B >\n");
	idx =  get_dual_pivot(stack->b, upper_idx, lower_idx);
	val.p1 = stack->b->data[idx.l];
	val.p2 = stack->b->data[idx.r];


	// PRT2
	// char tmp;
	// while (scanf("%c",&tmp) && tmp != '\n');



	sub_size = upper_idx - lower_idx + 1;


	if (is_desc(stack->a, stack->a->top, 0) && is_asc(stack->b, stack->b->top, 0))
	{
		while (stack->b->top >= 0)
			pa;
		return (-1);
	}

	if (sub_size < 1)
		return (0);


	if (sub_size == 1)
	{
		pa;
		return (0);
	}

	if (upper_idx < 0 || lower_idx < 0)
		return (0);




/******************************************************************************/
	/*
		큰 값을 A 로 보내기
	*/

	i = -1;
	while (++i < sub_size)
	{
		if (stack->b->data[stack->b->top] > val.p2)
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

	i = -1;
	while (++i < rotated_while_find_large)
	{
		rrb;
		if (stack->b->data[stack->b->top] == val.p2)
		{

			pa;
			poped_while_find_large++;
		}
	}


/******************************************************************************/

	/*
		중간 값을 A 로 보내기
	*/

	i = -1;
	while (++i < sub_size - poped_while_find_large)
	{
		if (stack->b->data[stack->b->top] > val.p1)
		{

			pa;
			poped_while_find_mid++;
		}
		else
		{
			rb;
			rotated_while_find_mid++;
		}
	}


	i = -1;
	while (++i < rotated_while_find_mid)
	{
		rrb;
		if (stack->b->data[stack->b->top] == val.p1)
		{
			pa;
			poped_while_find_mid++;
		}
	}


/******************************************************************************/



	if (-1 == dual_qsort_a(stack, stack->a->top, stack->a->top - (poped_while_find_large + poped_while_find_mid) + 1))
		return -1;



	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - (sub_size - poped_while_find_mid - poped_while_find_large) + 1))
		return -1;


/******************************************************************************/

	return (0);
}






int	main(int argc, char **argv)
{
	int			i;
	long long	is_int;
	t_set		stack;

	i = argc;
	if (argc < 2)
		return 1;
	if ((stack.a = init_stack(argc - 1)) == NULL)
		return 2;
	if ((stack.b = init_stack(argc - 1)) == NULL)
		return 2;
	while (--i > 0)
	{
		if ((is_int = ft_atoi(argv[i])) == OVER_INTEGER)
			return 3;
		else
			push(stack.a, is_int);
	}


	/* 700 , 5500 */

	// sort_a_using_b(&stack, stack.a->top, 0, stack.a->data[get_median_index(stack.a, stack.a->top, 0)], 0);
	dual_qsort_a(&stack, stack.a->top, 0);
	// print_all(&stack);
}







