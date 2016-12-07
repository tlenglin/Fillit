/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:58:39 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 12:29:02 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*ft_strnewgrid(int arr_size)
{
	char	*str;
	int		i;

	str = ft_memalloc((arr_size + 1) * arr_size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, '.', (arr_size + 1) * arr_size);
	i = 0;
	while (str[i])
	{
		if ((i + 1) % (arr_size + 1) == 0)
			str[i] = '\n';
		i++;
	}
	return (str);
}

int		ft_display(t_tetri **tabtetri, t_grid *grid, int stock)
{
	int		i;
	t_coor	*position;
	t_fct	*fonction_type;
	int		j;
	char	*strgrid;

	i = 0;
	strgrid = ft_strnewgrid(grid->size);
	fonction_type = ft_type_initializing();
	while (i <= stock)
	{
		j = 0;
		position = fonction_type[tabtetri[i]->type](tabtetri[i]->x,
			tabtetri[i]->y);
		while (j < 4)
		{
			strgrid[(position[j].y - 1) * grid->size + (position[j].x - 1) +
			position[j].y - 1] = 'A' + i;
			j++;
		}
		i++;
	}
	ft_putstr(strgrid);
	return (1);
}
