/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:53:44 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/23 14:51:47 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_tetri
{
	int type;
	int x;
	int y;
}				t_tetri;

typedef struct	s_coor
{
	int	x;
	int	y;
}				t_coor;

typedef struct	s_grid
{
	int size;
	int freep;
	int cursor;
}				t_grid;

typedef t_coor *(*t_fct)(int, int);

int				ft_stock(int fd, char **tab);
char			*ft_strnewgrid(int arr_size);
int				parsinglast(char *tetri, t_tetri *t, int ligne);
int				recognition22_bis(int ligne, char *tetri, t_tetri *t);
int				recognition21_bis(int ligne, char *tetri, t_tetri *t);
int				recognition13_bis(int ligne, char *tetri, t_tetri *t);
int				recognition12_bis(int ligne, char *tetri, t_tetri *t);
int				recognition12_ter(int ligne, char *tetri, t_tetri *t);
int				recognition12_last(int ligne, char *tetri, t_tetri *t);
int				recognition11_bis(int ligne, char *tetri, t_tetri *t);
int				ft_free_square_bis(t_tetri **tabtetri, int tetri_placed,
	t_coor position, t_grid *grid);
t_coor			*ft_free_square_ter(t_tetri **tabtetri, int j);
int				algo_bis(t_tetri **tabtetri, t_grid *grid, int tetri_placed,
	int stock);
int				algo_ter(t_tetri **tabtetri, t_grid *grid, int tetri_placed,
	int stock);
int				ft_stock_bis(int i, char *buffer, char **tab, int j);
int				recognition11_ter(int ligne, char *tetri, t_tetri *t);
int				recognition11_last(int ligne, char *tetri, t_tetri *t);
int				ft_check_bis(t_tetri **tabtetri, int tetri_placed,
	t_coor *position);
int				parsing2(char *tetri, t_tetri *t, int ligne);
int				parsing1(char *tetri, t_tetri *t, int ligne);
int				ft_display(t_tetri **tabtetri, t_grid *grid, int stock);
int				parsing_tetri(char *tetri, t_tetri *t);
int				parsing_tetri_bis(char *tetri, t_tetri *t);
int				parsing_tetri_ter(char *tetri, t_tetri *t);
int				parsing(int ligne, char *tetri);
int				recognition3(int ligne, char *tetri, t_tetri *t);
int				recognition22(int ligne, char *tetri, t_tetri *t);
int				recognition21(int ligne, char *tetri, t_tetri *t);
int				recognition13(int ligne, char *tetri, t_tetri *t);
int				recognition12(int ligne, char *tetri, t_tetri *t);
int				recognition11(int ligne, char *tetri, t_tetri *t);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_sizegrid(int stock);
int				ft_creategrid(int stock, t_grid *grid);
int				algo(t_tetri **tabtetri, t_grid *grid, int tetri_placed,
	int stock);
int				ft_check(t_tetri **tabtetri, t_grid *grid, int tetri_placed);
t_fct			*ft_type_initializing(void);
int				ft_ingrid(t_grid *grid, t_coor *position);
int				ft_free_square(t_tetri **tabtetri, t_grid *grid,
	int tetri_placed);
t_coor			*type0(int x, int y);
t_coor			*type1(int x, int y);
t_coor			*type2(int x, int y);
t_coor			*type3(int x, int y);
t_coor			*type4(int x, int y);
t_coor			*type5(int x, int y);
t_coor			*type6(int x, int y);
t_coor			*type7(int x, int y);
t_coor			*type8(int x, int y);
t_coor			*type9(int x, int y);
t_coor			*type10(int x, int y);
t_coor			*type11(int x, int y);
t_coor			*type12(int x, int y);
t_coor			*type13(int x, int y);
t_coor			*type14(int x, int y);
t_coor			*type15(int x, int y);
t_coor			*type16(int x, int y);
t_coor			*type17(int x, int y);
t_coor			*type18(int x, int y);
int				ft_tab_in_tabtetri(int stock, char **tab, t_tetri **tabtetri);
t_tetri			**ft_init_tabtetri(void);
char			**ft_init_tab(void);
int				ft_stock_in_tab(char **tab, char *buffer, int i, int j);
int				ft_fillit(char **argv);
int				ft_count_hashtag(char **tab, int stock);

#endif
