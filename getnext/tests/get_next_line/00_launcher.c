/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   00_launcher.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 11:48:51 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 16:18:14 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int		gnl_launcher(void)
{
	t_unit_test		*testlist;

	testlist = NULL;
	ft_putendl("---GET NEXT LINE");
	load_test(&testlist, "Lenght 1 multiple lines", &gnl_test_01);
	load_test(&testlist, "Increasing length input", &gnl_test_02);
	load_test(&testlist, "Increasing wo EOL", &gnl_test_03);
	load_test(&testlist, "NULL at the beginning", &gnl_test_04);
	load_test(&testlist, "Empty Line", &gnl_test_05);
	return (launch_tests(&testlist));
}

