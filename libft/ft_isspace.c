/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:33:40 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 12:36:00 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return (c == '\n' || c == '\t' || c == ' ' ||
			c == '\v' || c == '\f' || c == '\r');
}