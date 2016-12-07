/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:24:32 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/22 15:31:10 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	recognition3(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("###.", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("#...", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 11;
		else if (ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 4;
		else if (ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 13;
		else
			return (-1);
	}
	else if (ft_strcmp(".###", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 11;
		else if (ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 4;
		else if (ft_strcmp("...#", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 13;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	recognition22(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("##..", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 1;
		else if (ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 16;
		else
			return (-1);
	}
	else if (recognition22_bis(ligne, tetri, t) == -1)
		return (-1);
	return (0);
}

int	recognition21(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("##..", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("#...", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 14;
		else if (ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 10;
		else
			return (-1);
	}
	else if (ft_strcmp(".##.", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 14;
		else if (ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 10;
		else
			return (-1);
	}
	else if (recognition21_bis(ligne, tetri, t) == -1)
		return (-1);
	return (0);
}

int	recognition13(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("#...", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("###.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 15;
		else
			return (-1);
	}
	else if (ft_strcmp(".#..", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("###.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 6;
		else if (ft_strcmp(".###", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 15;
		else
			return (-1);
	}
	else if (recognition13_bis(ligne, tetri, t) == -1)
		return (-1);
	return (0);
}

int	recognition12(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("#...", tetri + (ligne * 5)) == -10)
	{
		if ((ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("#...", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 7;
		else if ((ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".#..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 0;
		else
			return (-1);
	}
	else if (ft_strcmp(".#..", tetri + (ligne * 5)) == -10 &&
	recognition12_bis(ligne, tetri, t) == -1)
		return (-1);
	else if (ft_strcmp("..#.", tetri + (ligne * 5)) == -10 &&
	recognition12_ter(ligne, tetri, t) == -1)
		return (-1);
	else if (ft_strcmp("...#", tetri + (ligne * 5)) == -10 &&
	recognition12_last(ligne, tetri, t) == -1)
		return (-1);
	return (0);
}
