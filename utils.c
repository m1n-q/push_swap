/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:03:42 by mishin            #+#    #+#             */
/*   Updated: 2021/07/20 02:23:33 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int		get_median_index(t_stack *stack, int top, int bottom)
{
	if (top - bottom <= 1)
		return (top);
	if (stack->data[bottom] < stack->data[(top + bottom) / 2] && stack->data[(top + bottom) / 2] < stack->data[top])
		return ((top + bottom) / 2);
	if (stack->data[top] < stack->data[(top + bottom) / 2] && stack->data[(top + bottom) / 2] < stack->data[bottom])
		return ((top + bottom) / 2);

	if (stack->data[(top + bottom) / 2] < stack->data[bottom] && stack->data[bottom] < stack->data[top])
		return (bottom);
	if (stack->data[top] < stack->data[bottom] && stack->data[bottom] < stack->data[(top + bottom) / 2])
		return (bottom);

	if (stack->data[bottom] < stack->data[top] && stack->data[top] < stack->data[(top + bottom) / 2])
		return (top);
	if (stack->data[(top + bottom) / 2] < stack->data[top] && stack->data[top] < stack->data[bottom])
		return (top);


	return -1;
}

void	swap_data_tmp(t_stack *stack_a, t_stack *stack_b, int i, int j)
{
	long long	tmp;

	tmp = stack_a->data[i];
	stack_a->data[i] = stack_a->data[j];
	stack_a->data[j] = tmp;
}


// void	swap_data(t_stack *stack_a, t_stack *stack_b, int i, int j)
// {
// 	long long	val_i;
// 	long long	val_j;
// 	t_move_info	fir;
// 	t_move_info	sec;

// 	if (i == j)
// 		return;
// 	val_i = stack_a->data[i];
// 	val_j = stack_a->data[j];
// 	fir.count = 0;
// 	sec.count = 0;
// 	if (i > stack_a->size / 2)
// 		fir.direction = R;
// 	else
// 		fir.direction = RR;
// 	if (j > stack_a->size / 2)
// 		sec.direction = R;
// 	else
// 		sec.direction = RR;

// 	while (stack_a->data[stack_a->top] != val_i)
// 	{
// 		if (fir.direction == R)
// 			ra;
// 		else
// 			rra;
// 		fir.count++;
// 	}


// 	pb;
// 	while (stack_a->data[stack_a->top] != val_j)
// 	{
// 		if (sec.direction == R)
// 			ra;
// 		else
// 			rra;
// 		sec.count++;
// 	}
// 	pb;
// 	sb;
// 	pa;
// 	while (sec.count-- > 0)
// 	{
// 		if (sec.direction == R)
// 			rra;
// 		else
// 			ra;
// 	}
// 	pa;
// 	while (fir.count-- > 0)
// 	{
// 		if (fir.direction == R)
// 			rra;
// 		else
// 			ra;
// 	}
// }

// void	swap_data2(t_stack *stack_a, t_stack *stack_b, int i, int j)
// {
// 	long long	val_i;
// 	long long	val_j;
// 	t_move_info	fir;
// 	t_move_info	sec;

// 	if (i == j)
// 		return;
// 	val_i = stack_b->data[i];
// 	val_j = stack_b->data[j];
// 	fir.count = 0;
// 	sec.count = 0;
// 	if (i > stack_b->size / 2)
// 		fir.direction = R;
// 	else
// 		fir.direction = RR;
// 	if (j > stack_b->size / 2)
// 		sec.direction = R;
// 	else
// 		sec.direction = RR;

// 	while (stack_b->data[stack_b->top] != val_i)
// 	{
// 		if (fir.direction == R)
// 			rb;
// 		else
// 			rrb;
// 		fir.count++;
// 	}


// 	pa;
// 	while (stack_b->data[stack_b->top] != val_j)
// 	{
// 		if (sec.direction == R)
// 			rb;
// 		else
// 			rrb;
// 		sec.count++;
// 	}
// 	pa;
// 	sa;
// 	pb;
// 	while (sec.count-- > 0)
// 	{
// 		if (sec.direction == R)
// 			rrb;
// 		else
// 			rb;
// 	}
// 	pb;
// 	while (fir.count-- > 0)
// 	{
// 		if (fir.direction == R)
// 			rrb;
// 		else
// 			rb;
// 	}
// }


// void	sort_three_elems(t_stack *stack_a, t_stack *stack_b, int top, int bottom)
// {
// 	if (stack_a->data[top] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] <stack_a->data[bottom])
// 		return ;
// 	else if (stack_a->data[bottom] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] < stack_a->data[top])
// 		swap_data(stack_a, stack_b, top, bottom);


// 	else if (stack_a->data[bottom + 1] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[top])
// 	{
// 		swap_data(stack_a, stack_b, top, bottom);
// 		swap_data(stack_a, stack_b, top, bottom + 1);
// 	}
// 	else if (stack_a->data[top] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[bottom + 1])
// 	{
// 		swap_data(stack_a, stack_b, bottom + 1, bottom);
// 	}


// 	else if (stack_a->data[bottom] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom + 1])
// 	{
// 		swap_data(stack_a, stack_b, top, bottom + 1);
// 		swap_data(stack_a, stack_b, top, bottom);
// 	}
// 	else if (stack_a->data[bottom + 1] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom])
// 	{
// 		swap_data(stack_a, stack_b, top, bottom + 1);
// 	}
// }

// void	sort_three_elems_tmp(t_stack *stack_a, t_stack *stack_b, int top, int bottom)
// {
// 	if (stack_a->data[top] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] <stack_a->data[bottom])
// 		return ;
// 	else if (stack_a->data[bottom] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] < stack_a->data[top])
// 		swap_data_tmp(stack_a, stack_b, top, bottom);


// 	else if (stack_a->data[bottom + 1] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[top])
// 	{
// 		swap_data_tmp(stack_a, stack_b, top, bottom);
// 		swap_data_tmp(stack_a, stack_b, top, bottom + 1);
// 	}
// 	else if (stack_a->data[top] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[bottom + 1])
// 	{
// 		swap_data_tmp(stack_a, stack_b, bottom + 1, bottom);
// 	}


// 	else if (stack_a->data[bottom] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom + 1])
// 	{
// 		swap_data_tmp(stack_a, stack_b, top, bottom + 1);
// 		swap_data_tmp(stack_a, stack_b, top, bottom);
// 	}
// 	else if (stack_a->data[bottom + 1] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom])
// 	{
// 		swap_data_tmp(stack_a, stack_b, top, bottom + 1);
// 	}
// }

// void	sort_three_elems_rev(t_stack *stack_a, t_stack *stack_b, int top, int bottom)
// {
// 	if (stack_b->data[top] > stack_b->data[bottom + 1] && stack_b->data[bottom + 1] >stack_b->data[bottom])
// 		return ;
// 	else if (stack_b->data[bottom] > stack_b->data[bottom + 1] && stack_b->data[bottom + 1] > stack_b->data[top])
// 		swap_data2(stack_a, stack_b, top, bottom);


// 	else if (stack_b->data[bottom + 1] > stack_b->data[bottom] && stack_b->data[bottom] > stack_b->data[top])
// 	{
// 		swap_data2(stack_a, stack_b, top, bottom);
// 		swap_data2(stack_a, stack_b, top, bottom + 1);
// 	}
// 	else if (stack_b->data[top] > stack_b->data[bottom] && stack_b->data[bottom] > stack_b->data[bottom + 1])
// 	{
// 		swap_data2(stack_a, stack_b, bottom + 1, bottom);
// 	}


// 	else if (stack_b->data[bottom] > stack_b->data[top] && stack_b->data[top] >stack_b->data[bottom + 1])
// 	{
// 		swap_data2(stack_a, stack_b, top, bottom + 1);
// 		swap_data2(stack_a, stack_b, top, bottom);
// 	}
// 	else if (stack_b->data[bottom + 1] > stack_b->data[top] && stack_b->data[top] >stack_b->data[bottom])
// 	{
// 		swap_data2(stack_a, stack_b, top, bottom + 1);
// 	}
// }

int	get_direction(t_stack *stack, int to_be_top)
{
	int	direction;

	if (to_be_top > stack->top / 2)
		direction = R;
	else
		direction = RR;
	return (direction);
}


int	get_index(t_stack *stack, long long value)
{
	int	i;

	i = -1;
	while (++i <= stack->top)
		if (stack->data[i] == value)
			return (i);
	return (-1);

}







// void	quick_sort_beta(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, int depth)
// {
// 	int			pivot_idx;
// 	long long	pivot_val;
// 	int			sub_size;
// 	long long	upper_val;
// 	t_move_info	upper_to_top;

// 	if (depth == 5)
// 		return ;
// 	sub_size = upper_idx - lower_idx + 1;
// 	if (sub_size <= 1)
// 		return ;
// 	if (sub_size == 2)
// 	{
// 		if (stack_a->data[upper_idx] > stack_a->data[lower_idx])
// 			swap_data(stack_a, stack_b, upper_idx, lower_idx);
// 		return ;
// 	}
// 	if (sub_size == 3)
// 	{
// 		sort_three_elems(stack_a, stack_b, upper_idx, lower_idx);
// 		return ;
// 	}

// 	pivot_idx = get_median_index(stack_a, upper_idx, lower_idx);
// 	pivot_val = stack_a->data[pivot_idx];
// 	upper_val = stack_a->data[upper_idx];

// 	/* 이번 레벨의 upper bound 를 스택의 탑으로 보낸다 */
// 	upper_to_top.count = 0;
// 	upper_to_top.direction = get_direction(stack_a, upper_idx);
// 	while (stack_a->data[stack_a->top] != upper_val)
// 	{
// 		if (upper_to_top.direction == R)
// 			ra;
// 		else
// 			rra;
// 		upper_to_top.count++;
// 	}

// 	/* 작은 값을 B 로 보내기, 단, subproblem 의 경계까지만 */
// 	int	rotated_while_find_small = 0;
// 	int	poped_while_find_small = 0;
// 	int	i = 0;

// 	while (i++ < sub_size)							// O(sub_size)
// 	{
// 		if (stack_a->data[stack_a->top] < pivot_val)
// 		{
// 			pb;
// 			poped_while_find_small++;
// 		}
// 		else
// 		{
// 			ra;
// 			rotated_while_find_small++;
// 		}
// 	}
// 	/* stack_a 의 회전상태 복구 */
// 	while (rotated_while_find_small--)				// O(sub_size)
// 		rra;



// 	/* pivot 찾아서 B로 보내기 */
// 	int	rotated_while_find_pivot = 0;
// 	i = 0;
// 	while (stack_a->top >= 0 && i++ < (sub_size - poped_while_find_small))	// subproblem의 경계가 줄어든 만큼, 반영해주기.
// 	{																		// O(sub_size)
// 		if (stack_a->data[stack_a->top] == pivot_val)
// 			pb;
// 		else
// 		{
// 			ra;
// 			rotated_while_find_pivot++;
// 		}
// 	}
// 	/* stack_a 의 회전상태 복구 */
// 	while (rotated_while_find_pivot--)
// 		rra;


// 	/* 큰 값 찾아서 B로 보내기 */
// 	int	rotated_while_find_large = 0;
// 	i = 0;
// 	while (stack_a->top >= 0 && i++ < (sub_size - poped_while_find_small - 1))
// 	{
// 		if (stack_a->data[stack_a->top] > pivot_val)
// 			pb;
// 		else
// 		{
// 			ra;
// 			rotated_while_find_large++;
// 		}

// 	}

// 	/* stack_a 의 회전상태 복구 */
// 	while (rotated_while_find_large--)				//O(sub_size)
// 		rra;


// 	/**** subproblem 부분 제외한 stack_a는 원상태 ? ****/
// 	/**** subproblem 의 pivot 위치 확보. 이제 다시 분할 가능 ****/
// 	i = 0;
// 	while (i++ < sub_size)					// O(sub_size)
// 		pa;
// 	while (upper_to_top.count--)
// 	{
// 		if (upper_to_top.direction == R)
// 			rra;
// 		else
// 			ra;
// 	}

// 	pivot_idx = get_index(stack_a, pivot_val);
// 	quick_sort_beta(stack_a, stack_b, upper_idx, pivot_idx + 1, depth + 1);
// 	quick_sort_beta(stack_a, stack_b, pivot_idx - 1, lower_idx, depth + 1);
// }














// void	quick_sort_alpha(t_stack *stack_a,  t_stack *stack_b, int upper_idx, int lower_idx, int depth)
// {
// 	int			sub_size;
// 	int			pivot_idx;
// 	long long	pivot_val;
// 	long long	upper_val;
// 	t_move_info	upper_to_top;

// 	if (depth == 1)
// 		return ;

// 	sub_size = upper_idx - lower_idx + 1;
// 	if (sub_size <= 1)
// 		return ;
// 	if (sub_size == 2)
// 	{
// 		if (stack_a->data[upper_idx] > stack_a->data[lower_idx])
// 			swap_data(stack_a, stack_b, upper_idx, lower_idx);
// 		return ;
// 	}

// 	pivot_idx = get_median_index(stack_a, upper_idx, lower_idx);
// 	pivot_val = stack_a->data[pivot_idx];
// 	upper_val = stack_a->data[upper_idx];

// 	/*
// 		이번 레벨의 upper bound 를 스택의 탑으로 보낸다
// 		(n / 2)
// 	*/

// 	// upper_to_top.count = 0;
// 	// upper_to_top.direction = get_direction(stack_a, upper_idx);
// 	// while (stack_a->data[stack_a->top] != upper_val)
// 	// {
// 	// 	if (upper_to_top.direction == R)
// 	// 		ra;
// 	// 	else
// 	// 		rra;
// 	// 	upper_to_top.count++;
// 	// }


// 	/*
// 		작은 값을 B 로 보내기, 단, subproblem 의 경계까지만
// 		(sub_size)
// 	*/

// 	int	rotated_while_find_small = 0;
// 	int	i = 0;

// 	while (i++ < sub_size)
// 	{
// 		if (stack_a->data[stack_a->top] < pivot_val)
// 			pb;

// 		else
// 		{
// 			ra;
// 			rotated_while_find_small++;
// 		}
// 	}

// 	/*
// 		stack_a 의 회전상태 복구
// 		(sub_size)
// 	*/

// 	while (rotated_while_find_small--)
// 	{

// 		rra;
// 		if (stack_a->data[stack_a->top] == pivot_val)
// 			pb;		// 복구하면서 피벗 찾아서 B로 보내기
// 	}


// 	/**
// 	 **		subproblem 부분 제외한 stack_a는 원상태
// 	 **		subproblem 의 pivot 위치 확보. 이제 다시 분할 가능
// 	 **/


// 	/*
// 		B 에 보냈던 피벗, 작은값 다시 가져오기
// 		n/2
// 	*/

// 	// while (stack_b->top >= 0)					// 이 부분만 빼고 B에서도 정렬..?
// 	// 	pa;


// 	/*
// 		sub_problem 이외의 부분 돌려놓기
// 		(sub_size / 2)
// 	*/

// 	// while (upper_to_top.count--)
// 	// {
// 	// 	if (upper_to_top.direction == R)
// 	// 		rra;
// 	// 	else
// 	// 		ra;
// 	// }


// 	pivot_idx = get_index(stack_a, pivot_val);

// 	// quick_sort_alpha(stack_a, stack_b, pivot_idx - 1, lower_idx, depth + 1);
// 	// quick_sort_alpha(stack_a, stack_b, upper_idx, pivot_idx + 1, depth + 1);


// }
