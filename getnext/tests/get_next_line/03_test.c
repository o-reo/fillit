/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 15:49:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				gnl_test_03(void)
{
	int		fd;
	char	*line;
	char	str[100];
	int		c;
	int		ok;

	fd = open("in3.tst", O_RDONLY);
	c = 1;
	ok = 1;
	line = "";
	while ((c = get_next_line(fd, &line)) == 1)
		ok = ft_strcmp(line, ft_strcat(str, "a"));
	close(fd);
	return(ok ? 0 : -1);
}
