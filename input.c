/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:39:22 by mishin            #+#    #+#             */
/*   Updated: 2021/07/09 18:26:56 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

long long		ft_atoi(const char *str)
{
	long long	ret;
	int 		sign;

	ret = 0;
	sign = 1;

	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret *= 10;
			ret += *str - '0';
		}
		else
			break;
		str++;
	}
	if ((sign * ret) < -2147483648 || (sign * ret) > 2147483647)
		return (-2222222222LL);
	else
		return ((sign * ret));
}