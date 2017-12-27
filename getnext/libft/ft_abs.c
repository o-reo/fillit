/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_abs.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:34:39 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 14:44:35 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_abs(int n)
{
	unsigned int	un;

	un = (unsigned int)n;
	if (n < 0)
		un = -n;
	return (un);
}
