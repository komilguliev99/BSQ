/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:10:15 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/27 03:25:38 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TOOLS_H

# define FILE_TOOLS_H
# include "list.h"
# include "bsq.h"

# define BUF_SIZE 2048

int			readf_to_list(char *file_path, t_list **list,
		t_bsq_info *info, int state);
int			calc_str_length(char *str, t_bsq_info *in, t_list *list, int fl);
char		**list_to_argv(t_list *list, t_bsq_info *info);
char		*copy_str(char *str, int len);
char		*get_first_line(t_list *list);
void		get_bsq(char *str, int count, t_bsq_info *info);
void		set_argv_item(char *str, char **argv, int *x, int *y);

#endif
