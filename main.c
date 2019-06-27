/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:46:40 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 06:22:13 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include "ft_tools.h"
#include "file_tools.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void	allocate_bsq(t_bsq_info **bsq)
{
	*bsq = malloc(sizeof(t_bsq_info));
	(*bsq)->sq = malloc(sizeof(t_square));
	(*bsq)->sq->cord = malloc(sizeof(t_point));
	(*bsq)->sq->length = 0;
	(*bsq)->sq->cord->x = -1;
	(*bsq)->sq->cord->y = -1;
}

void	run_programm(int state, char *file_path)
{
	t_bsq_info		*info;
	t_list			*list;

	list = NULL;
	allocate_bsq(&info);
	if (readf_to_list(file_path, &list, info, state))
	{
		info->map = list_to_argv(list, info);
		clear_list(&list);
		calc_square(info, 0, 0);
		printf("END OF CALC\n");
		show_map(info, info->map);
	}
	else
		write(2, "map error", 9);
	clear_bsq(info);
}

int		main(int ac, char **av)
{
	int			i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			run_programm(1, av[i]);
			if (i < ac - 1)
				ft_putchar('\n');
			i++;
		}
	}
	else
		run_programm(0, "no_file");
	return (0);
}
