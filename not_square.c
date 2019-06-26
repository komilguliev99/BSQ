/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:09:42 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 18:23:46 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			not_in_square(int i, int j, t_square *sq)
{
	if (i >= sq->cord->y && i < sq->cord->y + sq->length
			&& j >= sq->cord->x && j < sq->cord->x + sq->length)
		return (0);
	return (1);
}
