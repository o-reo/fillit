/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reading.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:58:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 17:06:39 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

int			check_line(char *line)
{
	int		i;

	if (ft_strlen(line) != 4)
		return (0);
	i = 0;
	while ((line[i] == '.' || line[i] == '#') && line[i])
		i++;
	if (!line[i])
		return (1);
	return (0);
}

int			check_nbhood(char **bloc, int i, int j)
{
	int		nbhrs;

	nbhrs = 0;
	if (i > 0)
		nbhrs += (bloc[i - 1][j] == '#');
	if (j > 0)
		nbhrs += (bloc[i][j - 1] == '#');
	if (bloc[i][j + 1])
		nbhrs += (bloc[i][j + 1] == '#');
	if (bloc[i + 1])
		nbhrs += (bloc[i + 1][j] == '#');
	return (nbhrs);
}

int			check_blocks(char **bloc)
{
	int		nb;
	int		i;
	int		j;
	int		nbhrs;

	nb = 0;
	i = 0;
	nbhrs = 0;
	while (bloc[i])
	{
		j = 0;
		while (bloc[i][j])
		{
			if (bloc[i][j] == '#' && !(check_nbhood(bloc, i, j)))
				return (0);
			if (bloc[i][j] == '#' && check_nbhood(bloc, i, j) <= 1)
				nbhrs++;
			nb = bloc[i][j] == '#' ? nb + 1 : nb;
			j++;
		}
		i++;
	}
	return (nb == 4 && nbhrs <= 3);
}

int			check_tetra(char **bloc)
{
	int		i;
	int		ok;

	i = 0;
	ok = check_blocks(bloc);
	while (bloc[i])
	{
		ok = ok && check_line(bloc[i]);
		i++;
	}
	if (i != 4)
		return (0);
	return (ok);
}

int			read_tetris(t_tetris **tets, char *filename)
{
	int			fd;
	char		buff[21];
	int			valid[3];
	char		**bloc;

	valid[0] = 1;
	valid[1] = 21;
	valid[2] = 0;
	buff[20] = '\n';
	fd = open(filename, O_RDONLY);
	while (valid[0] && valid[1] > 20 && buff[20] == '\n')
	{
		valid[1] = read(fd, buff, 21);
		bloc = ft_strsplit(buff, '\n');
		valid[0] = valid[0] && check_tetra(bloc);
		ft_bzero((void *)buff, 20);
		if (valid[0])
			tets[valid[2]] = to_tetris(bloc);
		if (valid[0] && !(tets[valid[2]]))
			return (0);
		valid[2]++;
	}
	tets[valid[2]] = NULL;
	close(fd);
	return (valid[1] == 20 && valid[0] ? valid[2] : 0);
}
