/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:27:06 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 14:54:04 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_count_hashtag(char **tab, int stock)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stock + 1)
	{
		j = 0;
		count = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				count++;
			j++;
		}
		if (count != 4)
			return (0);
		i++;
	}
	return (1);
}

int		ft_fillit(char **argv)
{
	int		fd;
	char	**tab;
	int		stock;
	t_tetri	**tabtetri;
	t_grid	*grid;

	if (!(grid = (t_grid*)malloc(sizeof(t_grid))))
		return (0);
	if (!(tab = ft_init_tab()))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if ((stock = ft_stock(fd, tab)) != -1)
	{
		if (ft_count_hashtag(tab, stock))
		{
			if (ft_tab_in_tabtetri(stock, tab, tabtetri = ft_init_tabtetri()))
			{
				if (ft_creategrid(stock + 1, grid) && algo(tabtetri, grid,
					0, stock) && ft_display(tabtetri, grid, stock))
					return (1);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_fillit(argv)))
			ft_putendl("error");
	}
	else
		ft_putendl("usage: fillit input_file");
	return (0);
}
