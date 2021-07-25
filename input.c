/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:39:22 by mishin            #+#    #+#             */
/*   Updated: 2021/07/24 00:15:43 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || \
		c == '\t' || \
		c == '\n' || \
		c == '\v' || \
		c == '\f' || \
		c == '\r')
		return (1);
	return (0);
}

static long long	atonum(const char *str, int *len)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	if ((*str == '-' || *str == '+') && ++(*len))
		if (*str++ == '-')
			sign *= -1;
	if (!('0' <= *str && *str <= '9'))
		return (NON_NUMERIC);
	while (*str)
	{
		(*len)++;
		if ('0' <= *str && *str <= '9')
			ret = (ret * 10) + (*str - '0');
		else
		{
			(*len)--;
			break ;
		}
		str++;
	}
	if ((sign * ret) < -2147483648 || (sign * ret) > 2147483647)
		return (OVER_INTEGER);
	return ((sign * ret));
}

int	input_to_ll(t_ll_handler *ll, char *arg)
{
	t_ll			*new;
	int				len;
	int				i;

	new = NULL;
	i = -1;
	while (arg[++i])
	{
		len = 0;
		if (is_space(arg[i]))
			continue ;
		if (arg[i] != '-' && arg[i] != '+' && !('0' <= arg[i] && arg[i] <= '9'))
			return (ll_clear(&(ll->head)));
		new = ll_new(atonum(arg + i, &len));
		if (!new || new->data == OVER_INTEGER || new->data == NON_NUMERIC)
			return (ll_clear(&(ll->head)));
		ll_push(&(ll->head), new);
		ll->size++;
		i += len - 1;
	}
	return (0);
}

void	ll_to_stack(t_ll **head, t_stack *stack)
{
	t_ll	*cur;
	int		i;

	cur = *head;
	i = stack->size;
	stack->top = stack->size - 1;
	while (cur)
	{
		stack->data[--i] = cur->data;
		cur = cur->next;
	}
	ll_clear(head);
}

int	check_dup(t_ll **head)
{
	t_ll	*cur_i;
	t_ll	*cur_j;

	cur_i = *head;
	while (cur_i)
	{
		cur_j = *head;
		while (cur_j != cur_i)
		{
			if (cur_i->data == cur_j->data)
				return (ll_clear(head));
			cur_j = cur_j->next;
		}
		cur_i = cur_i->next;
	}
	return (0);
}
