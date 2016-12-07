/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:20:48 by efichot           #+#    #+#             */
/*   Updated: 2016/11/23 13:10:45 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_stock_in_tab(char **tab, char *buffer, int i, int j)
{
	if (i == 20)
		return (1);
	if (i % 5 < 4)
	{
		if (buffer[0] != '#' && buffer[0] != '.')
			return (-1);
		else
			tab[j][i++] = buffer[0];
	}
	else if (i % 5 == 4)
	{
		if (buffer[0] != '\n')
			return (-1);
		else
			tab[j][i++] = '\n';
	}
	else if (i % 20 == 0)
	{
		if (buffer[0] == '\n')
			tab[j++][i] = '\0';
		else
			return (-1);
	}
	return (1);
}

int		ft_stock(int fd, char **tab)
{
	int		ret;
	char	buffer[2];
	int		i;
	int		nb_piece;

	nb_piece = 0;
	i = 0;
	while ((ret = read(fd, buffer, 1)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if (ft_stock_in_tab(tab, buffer, i, nb_piece) == -1)
			return (-1);
		i++;
		if (i == 21)
		{
			nb_piece++;
			i = 0;
		}
	}
	return (nb_piece);
}

char	**ft_init_tab(void)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 27)))
		return (NULL);
	while (i < 27)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * 20)))
			return (NULL);
		i++;
	}
	return (tab);
}

t_tetri	**ft_init_tabtetri(void)
{
	t_tetri	**tabtetri;
	int		i;
	t_tetri	*originaltetri;

	if (!(originaltetri = (t_tetri*)ft_memalloc(sizeof(*originaltetri) * 26)))
		return (0);
	if (!(tabtetri = (t_tetri**)ft_memalloc(sizeof(**tabtetri) * 26)))
		return (NULL);
	i = 0;
	while (i < 26)
	{
		tabtetri[i] = &originaltetri[i];
		i++;
	}
	return (tabtetri);
}

int		ft_tab_in_tabtetri(int stock, char **tab, t_tetri **tabtetri)
{
	int	i;

	i = 0;
	while (i <= stock)
	{
		if (parsing_tetri(tab[i], tabtetri[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}
