/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:30:45 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 16:58:46 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

char		*ft_trim(char *str)
{
	int		sz;

	while (ft_is_space(*str))
		str++;
	sz = 0;
	while (str[sz] != '\0')
		sz++;
	while (ft_is_space(str[sz]))
		sz--;
	str[sz + 1] = '\0';
	return (str);
}
