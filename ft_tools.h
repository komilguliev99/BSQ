/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:34:58 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/26 12:09:51 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H

# define FT_TOOLS_H

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int			ft_atoi(char *str);
int			ft_get_number(char **str);
int			ft_is_space(char c);
char		*ft_trim(char *str);
char		*ft_trim_l(char *str);
char		*ft_trim_r(char *str);

#endif
