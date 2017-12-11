/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 16:25:08 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 17:04:33 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		c;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	c = 1;
	while (get_next_line(fd, &str) == 1)
		ft_putendl(str);
	close(fd);
	return (0);
}
