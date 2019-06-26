/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:46:40 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 21:10:27 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include "ft_tools.h"
#include "file_tools.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


void	print_bsq(t_bsq_info *bsq)
{
	printf("%i, %c, %c, %c, %i\n",
			bsq->n_line,
			bsq->empty_c,
			bsq->obstacle_c,
			bsq->full_c,
			bsq->l_line
		  );
}


void	print_argv(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_bsq_info  *info;
	t_list		*list;
	t_square	*sq;
	int			i;
	char       **map;
	info = set_bsq_info("   6567238.o  ");
	print_bsq(info);
	//print_argv(av);
	list = NULL;
	printf("Read State: %i\n", readf_to_list("./test", &list, info));
	print_list(list);
	printf("AFTER LENGTH: %s\n", get_first_line(list));
	map = list_to_argv(list, info);
	ft_putstr("Was converted!\n");
	printf("L: %i\n", info->l_line);
	//print_argv(map);
	return (0);
}
