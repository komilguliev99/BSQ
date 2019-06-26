/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:56:37 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 21:13:09 by dcapers          ###   ########.fr       */
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
				break;
		if (sz)
			return (sz - 1);
		list = list->next;
	}
	return (0);
}

char		*get_first_line(t_list *list)
{
	int		len;
	char	*str;
	char	*str_it;

	len = get_length(list);
	printf("LENGOF:  %i\n", len);
	str = malloc(len + 1);
	while (list)
	{
		str_it = list->value;
		while (*str_it != '\0' && len)
		{
			*str = *str_it;
			str++;
			str_it++;
			len--;
		}
		list = list->next;
	}
	return (str);
}
