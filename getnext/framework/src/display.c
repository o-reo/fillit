/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 14:20:42 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/03 22:54:38 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"

void	ft_putstr(char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	to_error(char *print, int err)
{
	ft_putstr("--> ");
	ft_putstr(print);
	ft_putstr(": ");
	if (err == SIGSEGV)
		ft_putstr("SEGV");
	else if (err == SIGABRT)
		ft_putstr("ABRT");
	else if (err == SIGBUS)
		ft_putstr("BUSE");
	else if (err == 0)
		ft_putstr("OK");
	else if (err == 255)
		ft_putstr("KO");
	ft_putstr("\n");
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n1;

	n1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n1;
	}
	if (n1 < 10)
		ft_putchar_fd(n1 + '0', fd);
	else
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
}

void	display_resume(int nb_tests, int nb_success)
{
	ft_putstr("--RESUME--\n");
	ft_putnbr_fd(nb_success, 1);
	ft_putstr("/");
	ft_putnbr_fd(nb_tests, 1);
	ft_putstr("\n");
}
