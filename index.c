/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:03:42 by mishin            #+#    #+#             */
/*   Updated: 2021/07/25 10:52:00 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, long long val)
{
	int	i;

	i = -1;
	while (++i <= stack->top)
		if (stack->data[i] == val)
			return (i);
	return (-1);
}

int	get_median_index(long long *data, int top, int bottom)
{
	if (top - bottom <= 1)
		return (top);
	if (data[bottom] < data[(top + bottom) / 2] && \
		data[(top + bottom) / 2] < data[top])
		return ((top + bottom) / 2);
	if (data[top] < data[(top + bottom) / 2] && \
		data[(top + bottom) / 2] < data[bottom])
		return ((top + bottom) / 2);
	if (data[(top + bottom) / 2] < data[bottom] && \
		data[bottom] < data[top])
		return (bottom);
	if (data[top] < data[bottom] && \
		data[bottom] < data[(top + bottom) / 2])
		return (bottom);
	if (data[bottom] < data[top] && \
		data[top] < data[(top + bottom) / 2])
		return (top);
	if (data[(top + bottom) / 2] < data[top] && \
		data[top] < data[bottom])
		return (top);
	return (-1);
}

t_pivot_info	get_pivot_info(t_stack *stack, int upper_idx, int lower_idx)
{
	t_pivot_info	pivot;
	long long		*arr;
	long long		val;
	int				size;

	size = upper_idx - lower_idx + 1;
	arr = (long long *)malloc(sizeof(long long) * (size));
	if (!arr)
		return (((t_pivot_info){{-1, -1}, {-1L, -1L}}));
	ft_memcpy(arr, stack->data + lower_idx, size * sizeof(long long));
	my_qsort(arr, 0, size - 1);
	pivot.val.p1 = arr[size / 3];
	pivot.val.p2 = arr[2 * (size / 3)];
	free(arr);
	pivot.idx.p1 = get_index(stack, pivot.val.p1);
	pivot.idx.p2 = get_index(stack, pivot.val.p2);
	return (pivot);
}
