/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:10:15 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/24 19:33:45 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TOOLS_H

# define FILE_TOOLS_H
#include "list.h"

# define BUF_SIZE 1024

void		readf_to_list(char *file_path, t_list *list);
int			calc_str_length(t_list *list);
char		**list_to_argv(t_list *list);

#endif
