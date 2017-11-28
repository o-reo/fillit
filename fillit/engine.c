/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:48:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 18:02:38 by eruaud      ###    #+. /#+    ###.fr     */
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

int		test_tet(char **grid, t_tetris *tet, int *off)
{
	int		i;
	int		ok;

	i = 0;
	ok = 1;
	while (i < 4)
	{
		ok = ok && (grid[tet->blocs[i].y + off[1]][tet->blocs[i].x + off[0]] == '.');
		i++;
	}
	return (ok);
}

int		put_tet(char **grid, t_tetris *tet, int letter, int *off)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		grid[tet->blocs[i].y + off[1]][tet->blocs[i].x + off[0]] = 'A' + letter;
		i++;
	}
	return (1);
}

int		try_grid(t_tetris **tets, int size)
{
	char	*grid[size + 1];
	int		i;
	int		off[2];
	int		ok;

	i = 0;
	init_grid(grid, size);
	while (tets[i])
	{
		off[1] = 0;
		ok = 0;
		while (off[1] < size && !ok)
		{
			off[0] = 0;
			while (off[0] < size && !ok)
			{
				if(test_tet(grid, tets[i], off))
					ok = put_tet(grid, tets[i], i, off);
				off[0]++;
			}
			off[1]++;
		}
		i++;
	}
	ft_puttab_fd(grid, size, 1);
	return (ok);
}
