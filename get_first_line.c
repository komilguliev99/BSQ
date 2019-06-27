/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:56:37 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:53:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "file_tools.h"
#include <stdio.h>

int			get_length(t_list *list)
{
	int				i;
	int				sz;
	char			*str;

	sz = 0;
	while (list)
	{
		i = 0;
		str = list->value;
		while (str[i] != '\0')
			if (str[i] != '\n')
			{
				i++;
				sz++;
			}
			else
				break ;
		if (sz)
			return (sz);
		list = list->next;
	}
	return (0);
}

char		*get_first_line(t_list *list)
{
	int		len;
	int		i;
	char	*str;
	char	*str_it;

	len = get_length(list);
	str = malloc(len + 1);
	i = 0;
	while (list)
	{
		str_it = list->value;
		while (i < len && str_it[i] != '\0')
		{
			str[i] = str_it[i];
			i++;
		}
		list = list->next;
	}
	str[i] = '\0';
	return (str);
}
