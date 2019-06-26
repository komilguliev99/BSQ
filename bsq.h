/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:48:40 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 20:02:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_square
{
	t_point			*cord;
	int				length;
}					t_square;

typedef struct		s_bsq_info
{
	char			empty_c;
	char			obstacle_c;
	char			full_c;
	int				n_line;
	int				l_line;
	char			**map;
	t_square		*sq;
}					t_bsq_info;

void				bsq(char *file_path);
t_bsq_info			*set_bsq_info(char *str);
int					calc_square(t_bsq_info *info, int i, int j);
int					not_in_square(int i, int j, t_square *sq);
void				show_map(t_bsq_info *bsq, char **map);
int					is_map_sym(t_bsq_info *info, char c);

#endif
