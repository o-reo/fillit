/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sthandling.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 16:32:44 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 16:59:54 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

void		print_tetris(t_tetris *tet)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_putstr("Bloc ");
		ft_putnbr(i + 1);
		ft_putstr(" ->  x : ");
		ft_putnbr(tet->blocs[i].x);
		ft_putstr(" - y : ");
		ft_putnbr(tet->blocs[i].y);
		ft_putchar('\n');
		i++;
	}
}

t_tetris	*normalize(t_tetris *tet)
{
	int		i;
	int		xm;
	int		ym;

	xm = 99;
	ym = 99;
	i = 0;
	while (i < 4)
	{
		xm = tet->blocs[i].x < xm ? tet->blocs[i].x : xm;
		ym = tet->blocs[i].y < ym ? tet->blocs[i].y : ym;
		i++;
	}
	while (i--)
	{
		tet->blocs[i].x -= xm;
		tet->blocs[i].y -= ym;
	}
	return (tet);
}

t_tetris	*to_tetris(char **bloc)
{
	int			it;
	int			i;
	int			j;
	t_tetris	*tet;

	if (!bloc)
		return (NULL);
	if (!(tet = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	i = 0;
	it = 0;
	while (bloc[i])
	{
		j = 0;
		while (bloc[i][j])
		{
			tet->blocs[it].x = bloc[i][j] == '#' ? j : tet->blocs[it].x;
			tet->blocs[it].y = bloc[i][j] == '#' ? i : tet->blocs[it].y;
			it += (bloc[i][j] == '#');
			j++;
		}
		i++;
	}
	return (normalize(tet));
}
