/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:46:40 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 17:23:15 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include "bsq.h"
#include "ft_tools.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;

	i = 1;
	ft_putstr("HHHHaH");
	ft_putnbr(8899);
	ft_putnbr(ft_get_number(&av[1]));
	return (0);
}
