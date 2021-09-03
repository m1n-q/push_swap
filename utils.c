/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:08:54 by mishin            #+#    #+#             */
/*   Updated: 2021/09/03 11:29:40 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s++)
		ret++;
	return (ret);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_tmp;
	unsigned char		*dst_tmp;
	size_t				i;

	src_tmp = src;
	dst_tmp = dst;
	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}

void	my_qsort(long long *arr, int start, int end)
{
	long long	tmp;
	long long	pv;
	int			l;
	int			r;
	int			p;

	if (start >= end)
		return ;
	p = get_median_index(arr, end, start);
	pv = arr[p];
	l = start;
	r = end;
	while (l < r)
	{
		while (arr[l] < pv)
			l++;
		while (arr[r] > pv)
			r--;
		tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
	}
	my_qsort(arr, start, r - 1);
	my_qsort(arr, r + 1, end);
}
