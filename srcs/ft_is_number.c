/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:48:57 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/07 21:48:57 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *str)
{
	int		i;

	if (!str || !str[0])
		return (0);
	i = -1;
	if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) != 1)
		i = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	if (ft_strlen(str) > 10)
		return (0);
	if ((ft_strlen(str) == 10) && (ft_strcmp(str, "2147483647") > 0))
		return (0);
	return (1);
}
