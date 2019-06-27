/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:53:56 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 01:42:31 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "ft_tools.h"

t_list		*new_list(char *new_val)
{
	t_list		*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->value = new_val;
	tmp->next = NULL;
	return (tmp);
}

void		push(t_list **list, char *new_val)
{
	t_list		*l_list;

	l_list = *list;
	if (l_list)
	{
		while (l_list->next)
			l_list = l_list->next;
		l_list->next = new_list(new_val);
	}
	else
		*list = new_list(new_val);
}

char		*shift(t_list **list)
{
	t_list		*l_list;
	char		*value;

	value = NULL;
	if (*list)
	{
		l_list = *list;
		value = l_list->value;
		*list = (*list)->next;
		free(l_list);
	}
	return (value);
}

void		print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->value);
		list = list->next;
	}
}

void		clear_list(t_list **list)
{
	t_list		*l_list;

	while (*list)
	{
		l_list = *list;
		*list = (*list)->next;
		free(l_list);
	}
	*list = NULL;
}
