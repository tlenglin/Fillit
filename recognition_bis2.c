/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_bis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:29:58 by efichot           #+#    #+#             */
/*   Updated: 2016/11/22 15:30:48 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	recognition12_last(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("...#", tetri + (ligne * 5)) == -10)
	{
		if ((ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..#.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 17;
		else if ((ft_strcmp("..##", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("...#", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 5;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	recognition11_bis(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp(".#..", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp(".#..\n.#..\n.#..\n.#..", tetri) == -10)
			t->type = 3;
		else if ((ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("##..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 12;
		else if ((ft_strcmp(".#..", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".##.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 8;
		else
			return (-1);
	}
	return (0);
}

int	recognition11_ter(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("..#.", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("..#.\n..#.\n..#.\n..#.", tetri) == -10)
			t->type = 3;
		else if ((ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp(".##.", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 12;
		else if ((ft_strcmp("..#.", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..##", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 8;
		else
			return (-1);
	}
	return (0);
}

int	recognition11_last(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("...#", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("...#\n...#\n...#\n...#", tetri) == -10)
			t->type = 3;
		else if ((ft_strcmp("...#", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("..##", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 12;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	recognition11(int ligne, char *tetri, t_tetri *t)
{
	if (ft_strcmp("#...", tetri + (ligne * 5)) == -10)
	{
		if (ft_strcmp("#...\n#...\n#...\n#...", tetri) == -10)
			t->type = 3;
		else if ((ft_strcmp("#...", tetri + ((ligne + 1) * 5)) == -10) &&
		(ft_strcmp("##..", tetri + ((ligne + 2) * 5)) == -10))
			t->type = 8;
		else
			return (-1);
	}
	else if (ft_strcmp(".#..", tetri + (ligne * 5)) == -10 &&
	recognition11_bis(ligne, tetri, t) == -1)
		return (-1);
	else if (ft_strcmp("..#.", tetri + (ligne * 5)) == -10 &&
	recognition11_ter(ligne, tetri, t) == -1)
		return (-1);
	else if (ft_strcmp("...#", tetri + (ligne * 5)) == -10 &&
	recognition11_last(ligne, tetri, t) == -1)
		return (-1);
	return (0);
}
