/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:54:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 17:06:36 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

int		ft_sqrt(int n)
{
	int		sq;

	sq = 1;
	while (sq * sq < n)
		sq++;
	return (sq);
}

int		main(int ac, char **av)
{
	t_tetris	*tets[30];
	int			ok;
	int			i;
	int			nb;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	nb = read_tetris(tets, av[1]);
	ok = 0;
	i = ft_sqrt(4 * nb);
	if (nb > 0 && nb <= 26 && *tets)
	{
		while (!ok)
		{
			ok = try_grid(tets, i);
			i++;
		}
	}
	if (nb == 0 || *tets == NULL || !ok)
		ft_putstr("error\n");
	return (0);
}
