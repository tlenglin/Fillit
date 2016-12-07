/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:01:43 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/22 15:31:38 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	recognition22_bis(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp(".##.", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 18;
		else if (ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 1;
		else if (ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 16;
		else
			return (-1);
	}
	else if (ft_strcmp("..##", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 18;
		else if (ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 1;
		else
			return (-1);
	}
	return (0);
}

int	recognition21_bis(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("..##", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 14;
		else if (ft_strcmp("...#", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 10;
		else
			return (-1);
	}
	return (0);
}

int	recognition13_bis(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("..#.", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("###.", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 9;
		else if (ft_strcmp(".###", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 6;
		else
			return (-1);
	}
	else if (ft_strcmp("...#", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp(".###", tetri + ((ligne + 1) * 5)) == -10)
			t->type = 9;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	recognition12_bis(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp(".#..", tetri + (ligne * 5)) == -10)
	{
		if ((ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("#...", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 17;
		else if ((ft_strcmp("##..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".#..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 5;
		else if ((ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".#..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 7;
		else if ((ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..#.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 0;
		else
			return (-1);
	}
	return (0);
}

int	recognition12_ter(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("..#.", tetri + (ligne * 5)) == -10)
	{
		if ((ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".#..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 17;
		else if ((ft_strcmp(".##.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..#.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 5;
		else if ((ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..#.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 7;
		else if ((ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("...#", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 0;
		else
			return (-1);
	}
	return (0);
}
