/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bsq_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:00:20 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:53:33 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "bsq.h"
#include "ft_tools.h"

void		get_bsq(char *str, int c_num, t_bsq_info *info)
{
	char			*token;
	int				i;

	token = malloc(c_num + 1);
	i = 0;
	while (i < c_num)
	{
		token[i] = str[i];
		i++;
	}
	token[i] = '\0';
	info->n_line = ft_atoi(token);
	info->empty_c = str[i];
	info->obstacle_c = str[i + 1];
	info->full_c = str[i + 2];
}

void		set_bsq_info(char *str, t_bsq_info *info)
{
	int			i;
	int			j;
	int			num;

	str = ft_trim_l(str);
	j = 0;
	while (str[j] >= '0' && str[j] <= '9' && str[j] != '\0')
		j++;
	i = 0;
	num = 0;
	i = 0;
	while (str[j + i] != '\0' && i < 3)
	{
		if (ft_is_space(str[i]))
			num++;
		i++;
	}
	if (num)
		i = i - num + 1;
	j = j - i + 3;
	get_bsq(str, j, info);
}
