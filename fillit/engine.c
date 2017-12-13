/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:48:06 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 17:41:08 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

void	init_grid(char **grid, int size)
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

	ok = 1;
	if (!tet)
		return (0);
	i = 0;
	while (i < 4 && ok)
	{
		ok = ok && (grid[tet->blocs[i].y + off[1]]
			[tet->blocs[i].x + off[0]] == '.');
		i++;
	}
	i = 0;
	while (i < 4 && (ok || letter == -19))
	{
		grid[tet->blocs[i].y + off[1]][tet->blocs[i].x + off[0]] = 'A' + letter;
		i++;
	}
	return (ok);
}

int		*max_tet(t_tetris *tet)
{
	int		*max;
	int		i;

	if (!(max = malloc(sizeof(int) * 2)))
		return (NULL);
	max[0] = 0;
	max[1] = 0;
	i = 0;
	while (i < 4)
	{
		if (tet->blocs[i].x > max[0])
			max[0] = tet->blocs[i].x;
		if (tet->blocs[i].y > max[1])
			max[1] = tet->blocs[i].y;
		i++;
	}
	return (max);
}

int		test_tet(char **grid, t_tetris **tet, int index, int size)
{
	int		i;
	int		off[3];
	int		ok;

	i = 0;
	off[0] = 0;
	off[1] = 0;
	off[2] = 1;
	if (!tet[index])
		return (1);
	while ((max_tet(tet[index])[1] + off[1]) < size && tet[index])
	{
		off[0] = 0;
		while ((max_tet(tet[index])[0] + off[0]) < size)
		{
			ok = put_tet(grid, tet[index], index, off);
			if (ok && test_tet(grid, tet, index + 1, size))
				return (1);
			if (ok)
				put_tet(grid, tet[index], -19, off);
			off[0]++;
		}
		off[1]++;
	}
	return (0);
}

int		try_grid(t_tetris **tets, int size)
{
	char	*grid[size + 1];
	int		ok;

	ok = 0;
	init_grid(grid, size);
	ok = test_tet(grid, tets, 0, size);
	if (ok)
		ft_puttab_fd(grid, size, 1);
	return (ok);
}
