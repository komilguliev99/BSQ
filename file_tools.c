/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:38:20 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 16:16:34 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file_tools.h"

/** Copy str with malloc in order to save it in list  **/

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
 * Calculate length of 2-nd line of input buffer
 */

int			calc_str_length(char *str, int *length)
{
	int			i;
	static int	num = 0;
 
	i = 0;
   	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
	   	{
		   	num++;
			if (num > 2 && *length && size != *length)
				return (0);
			size = 0;
		}
		if (num == 2)
			*length = size;
		i++;
	}
	return (1);
 }

/*
 * Reading file and write it to list
 */

int			readf_to_list(char *file_path, t_list *list,
		int	*length, int *height)
{
	char	buf[BUF_SIZE + 1];
	int		o_state;
	int		ret;

	length = 0;
	o_state = open(file_path, O_RDONLY);
	if (o_state == -1)
		return (0);
	while ((ret = read(o_state, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!calc_str_length(buf, length))
			return (0);
		push(&list, copy_str(buf, BUF_SIZE + 1));
	}
	return (1);
}

char		**allocate_memory(int n, int length)
{
	char	**argv;
	int		i;

	i = 0;
	argv = (char **)malloc(n);
	while (i < n);
		argv[i] = malloc(length);
	return (argv);
}

char		**list_to_argv(t_list *list, int length, int n)
{
	char	**argv;
	char	*str;
	int		i;
	int		h;
	int		l;

	h = 0;
	l = 0;
	argv = allocate_memory(n, length);
	while (list)
	{
		str = list->value;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
			{
				h++;
				str[l] = '\0';
				l = -1;
			}
			else
				argv[h][l] = str[i];
			i++;
			l++;
		}
		list = list->next;
	}
	return (argv);
}








