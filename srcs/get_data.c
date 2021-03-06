/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:23:08 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/08 23:05:50 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "al-cu.h"

int		get_data(t_data *d, char **av)
{
	if ((d->lines = ft_atoi(av[1])) < 6)
		return (eb_error1("lines have to be bigger than 5"));
	if ((d->columns = ft_atoi(av[2])) < 7)
		return (eb_error1("columns have to be bigger than 6"));
	if ((d->tab = (char **)malloc(sizeof(char *) * (d->lines + 1))) == NULL)
		return (eb_error1("error malloc line"));
	d->tab[d->lines] = 0;
	if (init_tab(d) == -1)
		return (-1);
	random_player(d);
	return (0);
}

int		init_tab(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < d->lines)
	{
		x = -1;
		if ((d->tab[y] = (char *)malloc(sizeof(char) * (d->columns + 1)))
			== NULL)
			return (eb_error1("error malloc columns"));
		d->tab[y][d->columns] = 0;
		while (++x < d->columns)
			d->tab[y][x] = ' ';
	}
	return (0);
}

void	clear_tab(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < d->lines)
	{
		x = -1;
		while (++x < d->columns)
			d->tab[y][x] = ' ';
	}
}

void	random_player(t_data *d)
{
	if (eb_random())
	{
		d->player = '1';
		d->computer = '2';
	}
	else
	{
		d->player = '2';
		d->computer = '1';
	}
	d->turn = '1';
}
