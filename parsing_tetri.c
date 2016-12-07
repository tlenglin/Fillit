/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:09:15 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/22 15:22:03 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	parsing_tetri(char *tetri, t_tetri *t)
{
	if (parsing(0, tetri) == 4)
		t->type = 2;
	else if (parsing(0, tetri) == 3)
	{
		if (recognition3(0, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(0, tetri) == 2)
	{
		if (parsing2(tetri, t, 0) == -1)
			return (-1);
	}
	else if (parsing(0, tetri) == 1)
	{
		if (parsing1(tetri, t, 0) == -1)
			return (-1);
	}
	else
	{
		if (parsing_tetri_bis(tetri, t) == -1)
			return (-1);
	}
	return (0);
}

int	parsing_tetri_bis(char *tetri, t_tetri *t)
{
	if (parsing(1, tetri) == 4)
		t->type = 2;
	else if (parsing(1, tetri) == 3)
	{
		if (recognition3(1, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(1, tetri) == 2)
	{
		if (parsing2(tetri, t, 1) == -1)
			return (-1);
	}
	else if (parsing(1, tetri) == 1)
	{
		if (parsing1(tetri, t, 1) == -1)
			return (-1);
	}
	else
	{
		if (parsing_tetri_ter(tetri, t) == -1)
			return (-1);
	}
	return (0);
}

int	parsing_tetri_ter(char *tetri, t_tetri *t)
{
	if (parsing(2, tetri) == 4)
		t->type = 2;
	else if (parsing(2, tetri) == 3)
	{
		if (recognition3(2, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(2, tetri) == 2)
	{
		if (parsing(3, tetri) == 2)
		{
			if (recognition22(2, tetri, t) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	else
	{
		if (parsinglast(tetri, t, 2) == -1)
			return (-1);
	}
	return (0);
}

int	parsing(int ligne, char *tetri)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (count != ligne)
	{
		if (tetri[i] == '\n')
			count++;
		i++;
	}
	count = 0;
	while (tetri[i] != '\n')
	{
		if (tetri[i] == '#')
			count++;
		i++;
	}
	return (count);
}
