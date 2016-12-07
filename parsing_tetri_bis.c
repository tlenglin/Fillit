/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tetri_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:58:57 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/18 15:18:19 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	parsing2(char *tetri, t_tetri *t, int ligne)
{
	if (parsing(ligne + 1, tetri) == 2)
	{
		if (recognition22(ligne, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(ligne + 1, tetri) == 1)
	{
		if (recognition21(ligne, tetri, t) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	parsing1(char *tetri, t_tetri *t, int ligne)
{
	if (parsing(ligne + 1, tetri) == 3)
	{
		if (recognition13(ligne, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(ligne + 1, tetri) == 2)
	{
		if (recognition12(ligne, tetri, t) == -1)
			return (-1);
	}
	else if (parsing(ligne + 1, tetri) == 1)
	{
		if (recognition11(ligne, tetri, t) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	parsinglast(char *tetri, t_tetri *t, int ligne)
{
	if (parsing(ligne, tetri) == 1)
	{
		if (parsing(ligne + 1, tetri) == 3)
		{
			if (recognition13(ligne, tetri, t) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	else
	{
		if (parsing(ligne + 1, tetri) == 4)
			t->type = 2;
		else
			return (-1);
	}
	return (0);
}
