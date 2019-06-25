/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:34:19 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/25 17:26:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_tools.h"
#include <stdio.h>

int		ft_get_number(char **str)
{
	char	*token;
	int		sz;
	int		i;

	while (ft_is_space(**str))
		(*str)++;
	sz = 0;
	while (str[0][sz] >= '0' && str[0][sz] <= '9' && str[0][sz] != '\0')
		sz++;
	i = 0;
	while (str[0][i] != '\0')
		i++;
	sz = sz - 3 + i;
	token = malloc(sz + 1);
	i = 0;
	while (**str != '\0' && **str >= '0' && **str <= '9' && i < sz)
	{
		token[i] = **str;
		(*str)++;
		i++;
	}
	token[i] = '\0';
	return (ft_atoi(token));
}
