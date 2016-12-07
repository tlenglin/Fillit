/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:51:30 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 12:29:40 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			ft_check_bis(t_tetri **tabtetri, int tetri_placed, t_coor *position)
{
	int		i;
	int		j;
	int		k;
	t_coor	*posj;
	t_fct	*fonction_type;

	j = -1;
	fonction_type = ft_type_initializing();
	while (++j < tetri_placed)
	{
		i = -1;
		posj = fonction_type[tabtetri[j]->type](tabtetri[j]->x, tabtetri[j]->y);
		while (++i < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (position[i].x == posj[k].x && position[i].y == posj[k].y)
					return (0);
				else
					k++;
			}
		}
	}
	return (1);
}

int			ft_free_square_bis(t_tetri **tabtetri, int tetri_placed, t_coor pos,
	t_grid *grid)
{
	int		j;
	int		k;
	int		l;
	t_coor	*positionj;

	j = -1;
	l = 0;
	while (++j < tetri_placed)
	{
		k = 0;
		pos.x = ((l) % grid->size) + 1;
		pos.y = ((l) / grid->size) + 1;
		positionj = ft_free_square_ter(tabtetri, j);
		while (k < 4)
		{
			if (positionj[k].x == pos.x && positionj[k].y == pos.y)
			{
				l++;
				j = 0;
				break ;
			}
			k++;
		}
	}
	return (0);
}

t_coor		*ft_free_square_ter(t_tetri **tabtetri, int j)
{
	t_coor	*posj;
	t_fct	*fonction_type;

	fonction_type = ft_type_initializing();
	posj = fonction_type[tabtetri[j]->type](tabtetri[j]->x, tabtetri[j]->y);
	return (posj);
}
