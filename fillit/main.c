/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:54:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:24:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fill.h"

int		main(int ac, char **av)
{
	t_tetris	*tets[26];
	int			ok;

	if (ac != 2)
		return (0);
	read_tetris(tets, av[1]);
	ok = try_grid(tets, 5);
	if (*tets == NULL || !ok)
		ft_putstr("error\n");
	return (0);
}
