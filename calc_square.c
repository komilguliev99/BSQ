/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:53:19 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 19:13:11 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	set_square(t_square *sq, int i, int j, int length)
{
	sq->cord->y = i;
	sq->cord->x = j;
	sq->length = length;
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
			calc_square(in, i + it + 1, j);
			calc_square(in, i, k + j + 1);
			called = 1;
		}
		if (!is_empty(in, i + k, j + it))
		{
			calc_square(in, i, j + it + 1);
			calc_square(in, i + k + 1, j);
			called = 1;
		}
		it++;
	}
	return (called);
}


int		calc_square(t_bsq_info *in, int i, int j)
{
	int		k;
	int		it;
	int		st;

	k = 0;
	while (in_map(in, k + i, k + j) && is_empty(in, i, j))
	{
		if (recalc_sq(in, i, j, k))
			break ;
		k++;
	}
	if (in->sq->length < k)
		set_square(in->sq, i, j, k);
	return (1);
}
