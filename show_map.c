/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:54:46 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 18:23:02 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_tools.h"

void	show_map(t_bsq_info *bsq, char **map)
{
	int			i;
	int			j;
	t_square	*sq;

	sq = bsq->sq;
	i = 0;
	while (i < bsq->n_line)
	{
		j = 0;
		while (j < bsq->l_line)
		{
			if (not_in_square(i, j, sq))
				ft_putchar(map[i][j]);
			else
				ft_putchar('X');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
