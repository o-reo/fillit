/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 16:18:04 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				gnl_test_05(void)
{
	int		fd;
	char	*str = NULL;
	int		c;

	fd = open("in1.tst", O_RDONLY);
	c = 1;
	c = get_next_line(fd, &str);
	ft_putendl("~~~DEBUG~~~");
	ft_putendl(str);
	ft_putstr("return :: ");
	ft_putnbr(c);
	ft_putendl("");
	/*c = get_next_line(fd, &str);*/
	/*ft_putendl(str);*/
	/*ft_putstr("return :: ");*/
	/*ft_putnbr(c);*/
	/*ft_putendl("");*/
	close(fd);
	return(c ? 0 : -1);
}
