
#include "push_swap.h"


int		get_median_index(t_stack *stack, int top, int bottom)
{
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



void	swap_data3(t_stack *stack_a, t_stack *stack_b, int i, int j)
{
	long long	val_i;
	long long	val_j;
	t_move_info	fir;
	t_move_info	sec;

	if (i == j)
		return;
	val_i = stack_a->data[i];
	val_j = stack_a->data[j];
	fir.count = 0;
	sec.count = 0;
	if (i > stack_a->size / 2)
		fir.direction = R;
	else
		fir.direction = RR;
	if (j > stack_a->size / 2)
		sec.direction = R;
	else
		sec.direction = RR;

	while (stack_a->data[stack_a->top] != val_i)
	{
		if (fir.direction == R)
			ra;
		else
			rra;
		fir.count++;
	}

	
	pb;
	while (stack_a->data[stack_a->top] != val_j)
	{
		if (sec.direction == R)
			ra;
		else
			rra;
		sec.count++;
	}
	pb;
	sb;
	pa;
	while (sec.count-- > 0)
	{	
		if (sec.direction == R)
			rra;
		else
			ra;
	}
	pa;
	while (fir.count-- > 0)
	{	
		if (fir.direction == R)
			rra;
		else
			ra;
	}
}


void	sort_three_elems(t_stack *stack_a, t_stack *stack_b, int top, int bottom)
{
	if (stack_a->data[top] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] <stack_a->data[bottom])
		return ;
	else if (stack_a->data[bottom] < stack_a->data[bottom + 1] && stack_a->data[bottom + 1] < stack_a->data[top])
		swap_data3(stack_a, stack_b, top, bottom);
	
	
	else if (stack_a->data[bottom + 1] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[top])
	{
		swap_data3(stack_a, stack_b, top, bottom);
		swap_data3(stack_a, stack_b, top, bottom + 1);
	}	
	else if (stack_a->data[top] < stack_a->data[bottom] && stack_a->data[bottom] < stack_a->data[bottom + 1])
	{	
		swap_data3(stack_a, stack_b, bottom + 1, bottom);
	}
	
	
	else if (stack_a->data[bottom] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom + 1])
	{	
		swap_data3(stack_a, stack_b, top, bottom + 1);
		swap_data3(stack_a, stack_b, top, bottom);
	}
	else if (stack_a->data[bottom + 1] < stack_a->data[top] && stack_a->data[top] <stack_a->data[bottom])
	{	
		swap_data3(stack_a, stack_b, top, bottom + 1);
	}
}

void	sort_three_elems_rev(t_stack *stack_a, t_stack *stack_b, int top, int bottom)
{
	if (stack_a->data[top] > stack_a->data[bottom + 1] && stack_a->data[bottom + 1] >stack_a->data[bottom])
		return ;
	else if (stack_a->data[bottom] > stack_a->data[bottom + 1] && stack_a->data[bottom + 1] > stack_a->data[top])
		swap_data3(stack_a, stack_b, top, bottom);
	
	
	else if (stack_a->data[bottom + 1] > stack_a->data[bottom] && stack_a->data[bottom] > stack_a->data[top])
	{
		swap_data3(stack_a, stack_b, top, bottom);
		swap_data3(stack_a, stack_b, top, bottom + 1);
	}	
	else if (stack_a->data[top] > stack_a->data[bottom] && stack_a->data[bottom] > stack_a->data[bottom + 1])
	{	
		swap_data3(stack_a, stack_b, bottom + 1, bottom);
	}
	
	
	else if (stack_a->data[bottom] > stack_a->data[top] && stack_a->data[top] >stack_a->data[bottom + 1])
	{	
		swap_data3(stack_a, stack_b, top, bottom + 1);
		swap_data3(stack_a, stack_b, top, bottom);
	}
	else if (stack_a->data[bottom + 1] > stack_a->data[top] && stack_a->data[top] >stack_a->data[bottom])
	{	
		swap_data3(stack_a, stack_b, top, bottom + 1);
	}
}

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