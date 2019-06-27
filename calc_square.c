/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:53:19 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:45:24 by dcapers          ###   ########.fr       */
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

int		is_empty(t_bsq_info *in, int i, int j)
{
	if (in->empty_c == in->map[i][j])
		return (1);
	return (0);
}

int		in_map(t_bsq_info *in, int i, int j)
{
	if (i < in->n_line && j < in->l_line)
		return (1);
	return (0);
}

int		recalc_sq(t_bsq_info *in, int i, int j, int k)
{
	int		it;
	int		called;

	it = 0;
	called = 0;
	while (it <= k)
	{
		if (!is_empty(in, i + it, k + j))
		{
			set_square(in->sq, i, j, k);
			if (i + it + 1 < in->n_line)
				called = calc_square(in, i + it + 1, j);
			if (k + j + 1 < in->l_line)
				called = calc_square(in, i, k + j + 1);
		}
		if (!is_empty(in, i + k, j + it))
		{
			set_square(in->sq, i, j, k);
			if (j + it + 1 < in->l_line)
				called = calc_square(in, i, j + it + 1);
			if (i + k + 1 < in->n_line)
				called = calc_square(in, i + k + 1, j);
		}
		it++;
	}
	return (called);
}

int		calc_square(t_bsq_info *in, int i, int j)
{
	int		k;

	k = 0;
	if (i == in->n_line - 1 && j == in->l_line)
		return (1);
	while (in_map(in, k + i, k + j) && is_empty(in, i + k, j + k))
	{
		if (recalc_sq(in, i, j, k))
			break ;
		k++;
	}
	if (k == 0)
		recalc_sq(in, i, j, k);
	return (1);
}
