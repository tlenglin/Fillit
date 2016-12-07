/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type10_14.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:38:21 by efichot           #+#    #+#             */
/*   Updated: 2016/11/22 15:42:48 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_coor	*type10(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x + 1;
	position[1].y = y;
	position[2].x = x + 1;
	position[2].y = y + 1;
	position[3].x = x + 1;
	position[3].y = y + 2;
	return (position);
}

t_coor	*type11(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x + 1;
	position[1].y = y;
	position[2].x = x + 2;
	position[2].y = y;
	position[3].x = x;
	position[3].y = y + 1;
	return (position);
}

t_coor	*type12(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x;
	position[1].y = y + 1;
	position[2].x = x - 1;
	position[2].y = y + 2;
	position[3].x = x;
	position[3].y = y + 2;
	return (position);
}

t_coor	*type13(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x + 1;
	position[1].y = y;
	position[2].x = x + 2;
	position[2].y = y;
	position[3].x = x + 2;
	position[3].y = y + 1;
	return (position);
}

t_coor	*type14(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x + 1;
	position[1].y = y;
	position[2].x = x;
	position[2].y = y + 1;
	position[3].x = x;
	position[3].y = y + 2;
	return (position);
}
