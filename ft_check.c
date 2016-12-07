/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:46:04 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 12:29:30 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			ft_check(t_tetri **tabtetri, t_grid *grid, int tetri_placed)
{
	t_coor	*position;
	t_fct	*fonction_type;

	fonction_type = ft_type_initializing();
	position = fonction_type[tabtetri[tetri_placed]->type](((grid->cursor - 1)
	% grid->size) + 1, ((grid->cursor - 1) / grid->size) + 1);
	if (ft_ingrid(grid, position) == 0)
		return (0);
	if (ft_check_bis(tabtetri, tetri_placed, position) == 0)
		return (0);
	return (1);
}

t_fct		*ft_type_initializing(void)
{
	static t_fct	fonction_type[19] = {&type0, &type1, &type2, &type3, &type4,
	&type5, &type6, &type7, &type8, &type9, &type10, &type11, &type12,
	&type13, &type14, &type15, &type16, &type17, &type18};

	return (fonction_type);
}

int			ft_ingrid(t_grid *grid, t_coor *position)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (position[i].x > grid->size || position[i].y > grid->size ||
			position[i].x <= 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_free_square(t_tetri **tabtetri, t_grid *grid, int tetri_placed)
{
	t_coor	position;

	position.x = 1;
	position.y = 1;
	ft_free_square_bis(tabtetri, tetri_placed, position, grid);
	if (position.y > grid->size)
	{
		grid->size++;
		return (-1);
	}
	return (((position.x - 1) + (position.y - 1) * grid->size) + 1);
}
