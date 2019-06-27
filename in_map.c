/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 05:03:09 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 05:04:24 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			in_map(t_bsq_info *in, int i, int j)
{
	if (i < in->n_line && j < in->l_line)
		return (1);
	return (0);
}
