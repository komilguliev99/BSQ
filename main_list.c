/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:33:52 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 17:06:09 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "list.h"
#include "ft_tools.h"

int		main(int ac, char **av)
{
	printf("ttt");
	av++;
	printf("uuu");
	printf("%i\n", ft_get_number(av));
	return (0);
}
