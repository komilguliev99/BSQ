/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:38:20 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:45:39 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file_tools.h"
#include "bsq.h"
#include <stdio.h>

/*
** Copy str with malloc in order to save it in list
*/

char		*copy_str(char *str, int len)
{
	char	*l_str;
	int		i;

	i = 0;
	l_str = malloc(len);
	while (str[i] != '\0')
	{
		l_str[i] = str[i];
		i++;
	}
	l_str[i] = '\0';
	return (l_str);
}

/*
** Calculate length of 2-nd line of input buffer
*/

int			calc_str_length(char *str, t_bsq_info *in, t_list *list, int flag)
{
	int				i;
	static int		num = 0;
	static int		size = 0;

	if (flag)
	{
		num = 0;
		size = 0;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			num++;
			if (num == 1)
				set_bsq_info(get_first_line(list), in);
			if (num > 2 && in->l_line && size - 1 != in->l_line)
				return (0);
			if (num == 2)
				in->l_line = size - 1;
			size = 0;
		}
		if (num >= 1 && !is_map_sym(in, str[i]) && str[i] != '\n')
			return (0);
		i++;
		size++;
	}
	return (1);
}

/*
** Reading file and write it to list
*/

int			readf_to_list(char *file_path, t_list **list,
		t_bsq_info *info, int st)
{
	char	buf[BUF_SIZE + 1];
	int		o_state;
	int		ret;

	if (st)
		o_state = open(file_path, O_RDONLY);
	else
		o_state = 0;
	if (o_state == -1)
		return (0);
	while ((ret = read(o_state, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		push(list, copy_str(buf, BUF_SIZE + 1));
		if (!calc_str_length(buf, info, *list, st))
			return (0);
		st = 0;
	}
	close(o_state);
	return (1);
}

char		**allocate_memory(int n, int length)
{
	char	**argv;
	int		i;

	i = 0;
	argv = (char **)malloc(n * sizeof(char *));
	while (i < n)
	{
		argv[i] = malloc(length);
		i++;
	}
	return (argv);
}

char		**list_to_argv(t_list *list, t_bsq_info *info)
{
	char	**argv;
	char	*str;
	int		h;
	int		l;

	h = 0;
	l = 0;
	argv = allocate_memory(info->n_line, info->l_line + 1);
	while (list)
	{
		str = list->value;
		set_argv_item(str, argv, &h, &l);
		list = list->next;
	}
	return (argv);
}
