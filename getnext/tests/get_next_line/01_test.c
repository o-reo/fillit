/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 16:18:20 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				gnl_test_01(void)
{
	int		fd;
	char	*str;
	int		c;
	int		ok;

	fd = open("in1.tst", O_RDONLY);
	c = 1;
	ok = 1;
	while ((c = get_next_line(fd, &str)) == 1)
		ok = ok && (*str == 'a');
	close(fd);
	return(ok ? 0 : -1);
}
