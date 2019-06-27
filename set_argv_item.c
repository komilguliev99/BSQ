/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argv_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 03:19:25 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:27:48 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_tools.h"

void	set_argv_item(char *str, char **argv, int *x, int *y)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && *y)
		{
			argv[*y - 1][*x] = str[i];
			*y = *y + 1;
			*x = -1;
		}
		else if (str[i] == '\n')
		{
			*y = *y + 1;
			*x = -1;
		}
		else if (*y)
			argv[*y - 1][*x] = str[i];
		i++;
		*x = *x + 1;
	}
}
