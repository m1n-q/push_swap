/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:23:48 by mishin            #+#    #+#             */
/*   Updated: 2021/07/17 22:52:49 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# define RR 1
# define R 0
typedef struct	s_stack
{
	int			top;
	int			size;
	long long	*data;
}				t_stack;

typedef struct	s_ll
{
	int			data;
	struct s_ll	*next;
}				t_ll;

typedef struct	s_move_info
{
	int			count;
	int			direction;
}				t_move_info;

typedef struct	s_set
{
	t_stack		*a;
	t_stack		*b;
}				t_set;

typedef struct	s_vector_idx
{
	int			l;
	int			r;
}				t_vector_idx;

typedef struct	s_vector_val
{
	long long	p1;
	long long	p2;
}				t_vector_val;


#endif
