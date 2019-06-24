/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:33:52 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/24 17:20:27 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "list.h"
#include "ft_tools.h"

int		main(void)
{
	t_list	*list;
	t_list	**l_list;

	list = NULL;
	l_list = &list;
	push(l_list, "title_list_1");
	push(l_list, "title_list_2");
	push(l_list, "title_list_3");
	ft_putstr(shift(l_list));
	push(l_list, "title_list_4");
	push(l_list, "title_list_5");
	ft_putstr(shift(l_list));
	push(l_list, "title_list_6");
	push(l_list, "title_list_7");
	clear_list(l_list);
	print_list(*l_list);
	return (0);
}
