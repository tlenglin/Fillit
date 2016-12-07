/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:02:03 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 11:48:49 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_sizegrid(int stock)
{
	int occupied_square;
	int i;

	occupied_square = stock * 4;
	i = 0;
	while (i * i < occupied_square)
		i++;
	return (i);
}

int		ft_creategrid(int stock, t_grid *grid)
{
	grid->size = ft_sizegrid(stock);
	grid->freep = 1;
	grid->cursor = 1;
	return (1);
}

int		algo(t_tetri **tabtetri, t_grid *grid, int tetri_placed, int stock)
{
	int i;
	int w;

	i = 0;
	if (tetri_placed == stock + 1)
		return (1);
	if (algo_bis(tabtetri, grid, tetri_placed, stock) == -1)
		return (-1);
	while (grid->cursor <= grid->size * grid->size)
	{
		if (ft_check(tabtetri, grid, tetri_placed) == 1)
		{
			tabtetri[tetri_placed]->x = ((grid->cursor - 1) % grid->size) + 1;
			tabtetri[tetri_placed]->y = ((grid->cursor - 1) / grid->size) + 1;
			w = grid->cursor;
			if (algo(tabtetri, grid, tetri_placed + 1, stock) == 1)
				return (1);
			else
				grid->cursor = w;
		}
		grid->cursor++;
	}
	if (algo_ter(tabtetri, grid, tetri_placed, stock) == 1)
		return (1);
	return (0);
}

int		algo_bis(t_tetri **tabtetri, t_grid *grid, int tetri_placed, int stock)
{
	int i;

	i = 0;
	if ((grid->freep = ft_free_square(tabtetri, grid, tetri_placed)) == -1)
	{
		grid->freep = 1;
		while (i < tetri_placed)
		{
			tabtetri[i]->x = 0;
			tabtetri[i]->y = 0;
			i++;
		}
		grid->size++;
		if (algo(tabtetri, grid, 0, stock) == 1)
		{
			grid->cursor = grid->freep;
			return (1);
		}
	}
	grid->cursor = grid->freep;
	return (0);
}

int		algo_ter(t_tetri **tabtetri, t_grid *grid, int tetri_placed, int stock)
{
	tabtetri[tetri_placed]->x = 0;
	tabtetri[tetri_placed]->y = 0;
	if (tetri_placed == 0)
	{
		tabtetri[0]->x = 0;
		tabtetri[0]->y = 0;
		grid->size++;
		if (algo(tabtetri, grid, 0, stock) == 1)
			return (1);
	}
	return (0);
}
