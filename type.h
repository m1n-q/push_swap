/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:23:48 by mishin            #+#    #+#             */
/*   Updated: 2021/07/23 13:14:52 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct s_stack
{
	int			top;
	int			size;
	long long	*data;
}				t_stack;

typedef struct s_ll
{
	long long	data;
	struct s_ll	*next;
}				t_ll;

typedef struct s_ll_handler
{
	struct s_ll	*head;
	int			size;
}				t_ll_handler;

typedef struct s_set
{
	t_stack		*a;
	t_stack		*b;
}				t_set;

typedef struct s_pivot_info
{
	struct s_vector_val
	{
		long long	p1;
		long long	p2;
	}				val;
	struct s_vector_idx
	{
		int			p1;
		int			p2;
	}				idx;
}					t_pivot_info;

typedef struct s_count
{
	struct s_pop
	{
		int		small;
		int		mid;
		int		large;
	}			pop;
	struct s_rotation
	{
		int		small;
		int		mid;
		int		large;
	}			rotation;
}				t_count;

#endif
