/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:15:01 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 13:47:09 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <cntl.h>
#include "file_tools.h"

int			readf_to_list(char *file_path, t_list *list)
{
	int		o_state;
	int		ret;
	char	buf[BUF_SIZE + 1];

	o_state = open(file_path, O_RDONLY);
	if (o_state == -1)
		return (0);
	while ((ret = read(o_state, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		push(&list, buf) 
	}
}
