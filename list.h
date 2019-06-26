/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:50:00 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 13:22:57 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

typedef struct		s_list
{
	char			*value;
	struct s_list	*next;
}					t_list;

t_list				*new_list(char *new_val);
void				push(t_list **list, char *new_val);
char				*shift(t_list **list);
void				print_list(t_list *list);
void				clear_list(t_list **list);

#endif
