/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type5_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:37:01 by efichot           #+#    #+#             */
/*   Updated: 2016/11/22 15:42:36 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_coor	*type5(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x - 1;
	position[1].y = y + 1;
	position[2].x = x;
	position[2].y = y + 1;
	position[3].x = x;
	position[3].y = y + 2;
	return (position);
}

t_coor	*type6(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x - 1;
	position[1].y = y + 1;
	position[2].x = x;
	position[2].y = y + 1;
	position[3].x = x + 1;
	position[3].y = y + 1;
	return (position);
}

t_coor	*type7(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x;
	position[1].y = y + 1;
	position[2].x = x + 1;
	position[2].y = y + 1;
	position[3].x = x;
	position[3].y = y + 2;
	return (position);
}

t_coor	*type8(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x;
	position[1].y = y + 1;
	position[2].x = x;
	position[2].y = y + 2;
	position[3].x = x + 1;
	position[3].y = y + 2;
	return (position);
}

t_coor	*type9(int x, int y)
{
	t_coor	*position;
	int		i;

	i = 0;
	position = (t_coor*)ft_memalloc(sizeof(t_coor) * 4);
	position[0].x = x;
	position[0].y = y;
	position[1].x = x - 2;
	position[1].y = y + 1;
	position[2].x = x - 1;
	position[2].y = y + 1;
	position[3].x = x;
	position[3].y = y + 1;
	return (position);
}
