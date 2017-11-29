/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:48:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 15:15:30 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

void	init_grid(char **grid, int	size)
{
	char	line[size + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < size)
	{
		line[j] = '.';
		j++;
	}
	line[size] = '\0';
	while (i < size)
	{
		grid[i] = ft_strdup(line);
		i++;
	}
}

int		put_tet(char **grid, t_tetris *tet, int letter, int *off)
{
	int		i;
	int		ok;

	i = 0;
	ok = 1;
	while (i < 4 && ok)
	{
		ok = ok && (grid[tet->blocs[i].y + off[1]][tet->blocs[i].x + off[0]] == '.');
			if (ok && off[2])
				grid[tet->blocs[i].y + off[1]][tet->blocs[i].x + off[0]] = 'A' + letter;
		i++;
	}
	return (ok);
}

int		test_tet(char **grid, t_tetris **tet, int index, int size)
{
	int		i;
	int		ok;
	int		off[3];

	i = 0;
	ok = 1;
	off[0] = 0;
	off[1] = 0;
	off[2] = 0;
	while (off[0] < size && tet[index])
	{
		while (off[1] < size)
		{
			ok = ok && put_tet(grid, tet[index], index, off);
			if (ok && test_tet(grid, tet, index + 1, size))
			{
				off[2] = 1;
				put_tet(grid, tet[index], index, off);
				return (1);
			}
			off[1]++;
		}
		off[0]++;
	}
	return (ok);
}

int		try_grid(t_tetris **tets, int size)
{
	char	*grid[size + 1];
	int		ok;

	init_grid(grid, size);
	ok = test_tet(grid, tets, 0, size);
	ft_puttab_fd(grid, size, 1);
	return (ok);
}
