/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:53:19 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 06:51:29 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	set_square(t_square *sq, int i, int j, int length)
{
	if (sq->length < length)
	{
		sq->cord->y = i;
		sq->cord->x = j;
		sq->length = length;
	}
}

int		recalc_sq(t_bsq_info *in, int i, int j, int k)
{
	int		it;
	int		called;

	printf("RE_CALC: %i, %i, %i\n", i, j, k);
	it = 0;
	called = 0;
	while (it <= k)
	{
		printf("i + it: %i,  j + it: %i\n", i + it, j + it);
		if (!is_empty(in, i + it, k + j))
		{
			set_square(in->sq, i, j, k);
			if (i + it + 1 < in->n_line)
				called = calc_square(in, i + it + 1, j + it);
			if (k + j + 1 < in->l_line)
				called = calc_square(in, i + it, k + j + 1);
		}
		if (!is_empty(in, i + k, j + it))
		{
			set_square(in->sq, i, j, k);
			if (j + it + 1 < in->l_line)
				called = calc_square(in, i + it, j + it + 1);
			if (i + k + 1 < in->n_line)
				called = calc_square(in, i + k + 1, j + it);
		}
		it++;
	}
	return (called);
}

int		check_horizontal(t_bsq_info *in, int i, int j, int k)
{
	int		it;

	it = 0;
	while (it < k)
		if (in_map(in, i + k, j + it) && is_empty(in, i + k, j + it))
			it++;
		else
			return (it);
	return (it);
}

int		check_vertical(t_bsq_info *in, int i, int j, int k)
{
	int		it;

	it = 0;
	while (it < k)
		if (in_map(in, i + it, j + k) && is_empty(in, i + it, j + k))
			it++;
		else
			return (it);
	return (it);
}

int		calc_square(t_bsq_info *in, int i, int j)
{
	int		k;
	int		hor;
	int		vert;

	k = 0;
	printf("RECUR: %i, %i, %i\n", i, j, k);
	if (i >= in->n_line - 1 || j >= in->l_line - 1)
		return (1);
	while (in_map(in, k + i, k + j))
	{
		hor = check_horizontal(in, i, j, k);
		vert = check_vertical(in, i, j, k);
		if (!(hor >= k && vert >= k))
			break ;
		k++;
	}
	printf("HORIZON: %i, VERTICAL: %i\n", hor, vert);
	set_square(in->sq, i, j, k);
	calc_square(in, i + k + 1, j);
	calc_square(in, i, j + k + 1);
	return (1);
}
