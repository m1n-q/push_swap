#include "push_swap.h"

int	sort_a_using_b(t_set *stack, int upper_idx, int lower_idx, long long pivot_val, int depth)
{
	int	sub_size;
	int	rotated_while_find_small = 0;
	int	poped_while_find_small = 0;
	int	i;

	// printf("\n< SORTING A >\n");
	// PRT
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
		if (stack->a->data[stack->a->top] < pivot_val)
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

/******************************************************************************/

	// O(sub_size / 2)
	i = -1;
	while (++i < rotated_while_find_small)
	{
		rra;
		if (stack->a->data[stack->a->top] == pivot_val)
		{
			pb;
			poped_while_find_small++;
		}
	}


/******************************************************************************/

	int			next_pivot_idx = get_median_index(stack->a, stack->a->top, stack->a->top - (sub_size - poped_while_find_small) + 1);
	long long	next_pivot_val = stack->a->data[next_pivot_idx];

	int			a = 0;
	int			b = 0;

	// printf("A -> A\ndepth %d -> %d\n", depth, depth + 1);
	a = sort_a_using_b(stack, stack->a->top, stack->a->top - (sub_size - poped_while_find_small) + 1 , next_pivot_val, depth + 1);

	// printf("A -> B\ndepth %d -> %d\n", depth, depth + 1);
	b = sort_b_using_a(stack, stack->b->top, stack->b->top - poped_while_find_small + 1, stack->b->data[get_median_index(stack->b, stack->b->top, stack->b->top - poped_while_find_small + 1)], depth + 1);

/******************************************************************************/

	if (a == -1 || b == -1)
		return (-1);

	// O(sub_size / 2)
	i = -1;
	while (stack->b->top >= 0 && ++i < poped_while_find_small)
		pa;

	return (0);
}



int	sort_b_using_a(t_set *stack, int upper_idx, int lower_idx, long long pivot_val, int depth)
{
	int	sub_size;
	int	rotated_while_find_large = 0;
	int	poped_while_find_large = 0;
	int	i;

	// printf("\n< SORTING B >\n");
	// PRT
	// char tmp;
	// while (scanf("%c",&tmp) && tmp != '\n');


	sub_size = upper_idx - lower_idx + 1;



	if (is_desc(stack->a, stack->a->top, 0) && is_asc(stack->b, stack->b->top, 0))
	{
		while (stack->b->top >= 0)
			pa;
		return (-1);
	}

	if (upper_idx < 0 || lower_idx < 0)
		return (0);

	if (sub_size < 1)
		return (0);

	if (is_asc(stack->b, upper_idx, lower_idx))
		return (0);







/******************************************************************************/
	/*
		큰 값을 A 로 보내기
	*/

	i = -1;
	while (++i < sub_size)
	{
		if (stack->b->data[stack->b->top] > pivot_val)
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

/******************************************************************************/

	i = -1;
	while (++i < rotated_while_find_large)
	{
		rrb;
		if (stack->b->data[stack->b->top] == pivot_val)
		{
			pa;
			poped_while_find_large++;
		}
	}

/******************************************************************************/

	int			next_pivot_idx = get_median_index(stack->b, stack->b->top, stack->b->top - (sub_size - poped_while_find_large) + 1);
	long long	next_pivot_val = stack->b->data[next_pivot_idx];
	int		a = 0;
	int		b = 0;

	// printf("B -> A\ndepth %d -> %d\n", depth, depth + 1);
	a = sort_a_using_b(stack, stack->a->top, stack->a->top - poped_while_find_large + 1, stack->a->data[get_median_index(stack->a, stack->a->top, stack->a->top - poped_while_find_large + 1)], depth + 1);

	// printf("B -> B\ndepth %d -> %d\n", depth, depth + 1);
	b = sort_b_using_a(stack, stack->b->top, stack->b->top - (sub_size - poped_while_find_large) + 1, next_pivot_val, depth + 1);


/******************************************************************************/




	/*
		만약 안쪽에서 이미 정렬되는 상황이 나온다면, 그걸 다시 돌리는 과정은 비효율.
	*/

	if (a == -1 || b == -1)
		return (-1);

	i = -1;
	while (stack->a->top >= 0 && ++i < poped_while_find_large)
		pb;
	return (0);
}




t_vector_idx	get_dual_pivot(t_stack *stack, int upper_idx, int lower_idx)
{
	t_vector_idx	v;
	int				tmp;

	if (upper_idx - lower_idx == 1)
	{
		if (stack->data[lower_idx] < stack->data[upper_idx] )
		{
			v.l = lower_idx;
			v.r = upper_idx;
		}

		else
		{
			v.l = upper_idx;
			v.r = lower_idx;
		}
		return (v);
	}

	v.l = get_median_index(stack, upper_idx, lower_idx + (upper_idx - lower_idx) / 2 + 1);
	v.r = get_median_index(stack, (lower_idx + upper_idx) / 2, lower_idx);
	if (stack->data[v.l] > stack->data[v.r])
	{
		tmp = v.l;
		v.l = v.r;
		v.r = tmp;
	}

	return (v);
}
